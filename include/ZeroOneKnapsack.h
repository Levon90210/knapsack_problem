#ifndef ZEROONEKNAPSACK_H
#define ZEROONEKNAPSACK_H
#include <vector>
#include <algorithm>

class ZeroOneKnapsack {
    int capacity;
    std::vector<int> weights;
    std::vector<int> bonuses;
    std::vector<std::vector<int>> memo;

    int solve(const int capacity, const int index) {
        if (capacity == 0 || index == 0) {
            memo[index][capacity] = 0;
            return 0;
        }
        if (memo[index][capacity] != -1) {
            return memo[index][capacity];
        }
        if (capacity >= weights[index - 1]) {
            memo[index][capacity] = solve(capacity - weights[index - 1], index - 1) + bonuses[index - 1];
        }
        memo[index][capacity] = std::max(memo[index][capacity], solve(capacity, index - 1));
        return memo[index][capacity];
    }

public:
    ZeroOneKnapsack(const int capacity, const std::vector<int>& weights, const std::vector<int>& bonuses)
        : capacity(capacity), weights(weights), bonuses(bonuses),
          memo(weights.size() + 1, std::vector<int>(capacity + 1, -1))
    {
        solve(capacity, weights.size());
    }

    int get_max_knapsack_bonus() const {
        return memo[weights.size()][capacity];
    }
};

#endif //ZEROONEKNAPSACK_H