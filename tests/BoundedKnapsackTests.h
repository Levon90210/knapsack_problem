#ifndef BOUNDEDKNAPSACKTESTS_H
#define BOUNDEDKNAPSACKTESTS_H

#include <gtest/gtest.h>
#include "BoundedKnapsack.h"

TEST(BoundedKnapsackTest, BasicCase)
{
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> bonuses = {3, 4, 5, 6};
    int capacity = 10;
    std::vector<int> bounds = {3, 2, 2, 1};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 15);
}

TEST(BoundedKnapsackTest, SingleItemMultipleTimes)
{
    std::vector<int> weights = {2};
    std::vector<int> bonuses = {5};
    int capacity = 8;
    std::vector<int> bounds = {3};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 15);
}

TEST(BoundedKnapsackTest, NoItems)
{
    std::vector<int> weights = {};
    std::vector<int> bonuses = {};
    int capacity = 10;
    std::vector<int> bounds = {};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 0);
}

TEST(BoundedKnapsackTest, ZeroCapacity)
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {3, 6, 9};
    int capacity = 0;
    std::vector<int> bounds = {11, 2, 345};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 0);
}

TEST(BoundedKnapsackTest, ExactMatch)
{
    std::vector<int> weights = {2, 3, 5};
    std::vector<int> bonuses = {10, 20, 30};
    int capacity = 5;
    std::vector<int> bounds = {2, 2, 2};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 30);
}

TEST(BoundedKnapsackTest, BoundOfZero)
{
    std::vector<int> weights = {3, 4, 5};
    std::vector<int> bonuses = {30, 40, 50};
    int capacity = 8;
    std::vector<int> bounds = {0, 1, 2};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 50);
}

TEST(BoundedKnapsackTest, LargeCapacitySmallItems)
{
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> bonuses = {1, 2, 3};
    int capacity = 100;
    std::vector<int> bounds = {90, 40, 25};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 100);
}

TEST(BoundedKnapsackTest, LargeNumbers)
{
    std::vector<int> weights = {10, 20, 30, 40, 50};
    std::vector<int> bonuses = {100, 200, 300, 400, 500};
    int capacity = 1000;
    std::vector<int> bounds = {100, 35, 30, 23, 19};
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);
    EXPECT_EQ(knapsack.get_max_knapsack_bonus(), 10000);
}

TEST(BoundedKnapsackTest, PerformanceTest)
{
    int n = 1000;
    std::vector<int> weights(n);
    std::vector<int> bonuses(n);
    for (int i = 0; i < n; ++i)
    {
        weights[i] = (i % 10) + 1;
        bonuses[i] = (i % 20) + 5;
    }
    int capacity = 5000;
    std::vector<int> bounds(n, 1000);
    BoundedKnapsack knapsack(capacity, weights, bonuses, bounds);

    int result = knapsack.get_max_knapsack_bonus();
    EXPECT_GT(result, 50000);
}

#endif //BOUNDEDKNAPSACKTESTS_H
