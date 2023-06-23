#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <thread>
#include <vector>

using Counter = std::map<std::string, std::size_t>;
using Counters = std::vector<Counter>;
using Words = std::vector<Counter::const_iterator>;

struct Word_count 
{
  std::string word;
  int count;
};

using Word_counts = std::vector<Word_count>;

std::string tolower(const std::string& str);

void count_words(std::istringstream& iss, Counter& counter);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

std::string tolower(const std::string& str) 
{
  std::string lower_str;
  std::transform(std::cbegin(str), std::cend(str), std::back_inserter(lower_str), [](unsigned char ch) { return std::tolower(ch); });
  return lower_str;
};

void count_words(std::istringstream& iss, Counter& counter) 
{
  std::for_each(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), [&counter](const std::string& s) { ++counter[tolower(s)]; });
}

void print_topk(std::ostream& stream, Word_counts& counts, const size_t k)
{
  std::for_each(std::begin(counts), std::begin(counts) + k, [&stream](Word_count& c) {stream << std::setw(4) << c.word << " " << c.count << '\n';});
}

void push_words_counts(Word_counts& counts, Counter& counter, const size_t k) 
{
  std::vector<std::pair<std::string, std::size_t>> vec{counter.begin(), counter.end()};
  std::partial_sort(std::begin(vec), std::begin(vec) + k, std::end(vec), [](auto lhs, auto& rhs) { return lhs.second > rhs.second; });

  std::for_each(std::begin(vec), std::begin(vec) + k, [&counts](std::pair<std::string, std::size_t>& v)
  {
  Word_count c;
  c.word = v.first;
  c.count = v.second;
  counts.push_back(c);
  });
}

bool comp_by_counts(const Word_count& a, const Word_count& b) 
{
  return a.count > b.count;
}

void topk_thread(std::vector<std::string>& lines, int start_pos, int n_lines, Counter& freq_dict) 
{
  if (n_lines == 0) 
  {
    int end_pos = lines.size();
    for (int i = start_pos; i < end_pos; ++i) 
    {
      std::string line = lines.at(i);
      std::istringstream iss(line);
      count_words(iss, freq_dict);
    }
  } 
  else 
  {
    for (int i = 0; i < n_lines; ++i) 
    {
      std::string line = lines.at(start_pos + i);
      std::istringstream iss(line);
      count_words(iss, freq_dict);
    }
  }
}

int main(int argc, char* argv[]) 
{
  if (argc < 4) 
  {
    std::cerr << "Usage: topk_words topk_words(3..10), [FILES...]\n";
    return EXIT_FAILURE;
  }

  size_t TOPK = std::atoi(argv[1]);
  if ((TOPK < 3) || (TOPK > 10)) 
  {
    std::cerr
        << "topk_words parameter value must be in the range from 3 to 10\n";
    return EXIT_FAILURE;
  }
  const int n_threads = 1;
  auto start = std::chrono::high_resolution_clock::now();
  Word_counts counts;
  Counters counters_vec;
  counters_vec.resize(n_threads);

  for (int i = 2; i < argc; ++i) 
  {
    std::ifstream input{argv[i]};
    if (!input.is_open()) {
      std::cerr << "Failed to open file " << argv[i] << '\n';
      return EXIT_FAILURE;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line)) {
      lines.emplace_back(line);
    }

    int n_lines = lines.size() / n_threads;
    std::vector<std::thread> topk_threads;

    for (int i = 0; i != n_threads; ++i) 
    {
      if (i == (n_threads - 1)) 
      {
        topk_threads.emplace_back(std::thread(topk_thread, std::ref(lines), i * n_lines, 0, std::ref(counters_vec.at(i))));
      } 
      else 
      {
        topk_threads.emplace_back(std::thread(topk_thread, std::ref(lines), i * n_lines, n_lines, std::ref(counters_vec.at(i))));
      }
    }

    for (auto& thread : topk_threads) 
    {
      thread.join();
    }

    for (int i = 0; i != n_threads; ++i) 
    {
      push_words_counts(counts, counters_vec.at(i), TOPK);
    }
  }

  int j = 1;
  for (auto& c : counts) 
  {
    for (int k = j; k != counts.size(); ++k) 
    {
      if (c.count != 0) 
      {
        if (c.word == counts.at(k).word) 
        {
          c.count += counts.at(k).count;
          counts.at(k).count = 0;
        }
      }
    }
    j++;
  }

  std::sort(counts.begin(), counts.end(), comp_by_counts);
  print_topk(std::cout, counts, TOPK);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";

  return 0;
}