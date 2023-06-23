#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "check_value.h"
#include "random_value.h"
#include "high_scores.h"

const int max_value = 100;
std::string set_name();

int main()
{
    int random_value_from_func = random_value(max_value);
    std::string name =  set_name();
    int attempts = check_value(random_value_from_func);
    write_data(name, attempts);
    high_score();

    return 0;
}

std::string set_name()
{
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;
    return user_name;
}
