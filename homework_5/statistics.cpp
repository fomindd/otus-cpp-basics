#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <numeric>
#include <cmath>
#include <bits/stdc++.h>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};


class Max : public IStatistics {
public:
	Max() : m_max{-std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
			if (next > m_max) {
					m_max = next;
			}
	}

	double eval() const override {
			return m_max;
	}

	const char * name() const override {
			return "max";
	}

private:
	double m_max;
};


class Mean : public IStatistics {
public:
	Mean() : m_mean{},vect{} {
	}

	void update(double next) override {
			vect.push_back(next);
			double sum = std::accumulate(vect.begin(), vect.end(), 0.00);
			m_mean = sum / vect.size();
	}

	double eval() const override {
			return m_mean;
	}

	const char * name() const override {
			return "mean";
	}

private:
	std::vector<double> vect; 
	double m_mean;
};


class Std : public IStatistics {
public:
	Std() : m_std{},vect{} {
	}

	void update(double next) override {
			double tsum;
			vect.push_back(next);
			double sum = std::accumulate(vect.begin(), vect.end(), 0.00);
			double mean = sum / vect.size();
			for(auto i: vect)  {
					tsum += pow(i - mean, 2);
			}
			m_std = sqrt( tsum / vect.size());
	}

	double eval() const override {
			return m_std;
	}

	const char * name() const override {
			return "std";
	}

private:
	std::vector<double> vect;
	double m_std;
};

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << std::setprecision(7) << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}