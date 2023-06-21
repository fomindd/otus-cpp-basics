#include <random_value.h>

int random_value(int value)
{
    std::srand(std::time(nullptr));
    const int random_value = std::rand() % value;
    return random_value;
}