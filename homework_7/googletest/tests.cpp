#include <gtest/gtest.h>
#include "checkcardnum.h"

TEST(TestCheckCardNum, correct_visa) {
    ASSERT_TRUE(checkcardnum("4561261212345467"));
}

TEST(TestCheckCardNum, incorrect_visa) {
    ASSERT_FALSE(checkcardnum("4561261212345465"));
}

TEST(TestCheckCardNum, skip_spaces) {
    ASSERT_TRUE(checkcardnum("4561 2612 1234 5467"));
}
