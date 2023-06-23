#include "check_value.h"

int current_value = 0;

int check_value(int value)
{
    int count = 0;

    std::cout << "Enter your guess:" << std::endl;

    do {
        std::cin >> current_value;
        count += 1;

        if (current_value > value) {
            std::cout << "less than " << current_value << std::endl;
        }
        else if (current_value < value) {
            std::cout << "greater than " << current_value << std::endl;
        }
        else {
            std::cout << "you win! attempts = " << count << std::endl;
            break;
        }

    } while(true);

    return count;
}
