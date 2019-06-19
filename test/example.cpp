/**
 * example.cpp
 *
 * By Sebastian Raaphorst, 2019.
 *
 * This is a simple test file to show how to get Google Test working.
 */

#include <gtest/gtest.h>

long factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n-1);
}

TEST(FactorialTest, Zero) {
    EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, Positive) {
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(5), 120);
}