#ifndef BOUNDEDKNAPSACK_H
#define BOUNDEDKNAPSACK_H
#include <vector>
#include <algorithm>

class BoundedKnapsack {
    int capacity;
    std::vector<int> weights;
    std::vector<int> bonuses;
    std::vector<int> bounds;
    std::vector<std::vector<int>> memo;

    int solve(const int capacity, const int index, const int remaining) {
        if (capacity == 0 || index == 0) {
            memo[index][capacity] = 0;
            return 0;
        }
        if (memo[index][capacity] != -1) {
            return memo[index][capacity];
        }
        if (capacity >= weights[index - 1] && remaining > 0) {
            memo[index][capacity] = solve(capacity - weights[index - 1], index, remaining - 1) + bonuses[index - 1];
        }
        memo[index][capacity] = std::max(memo[index][capacity], solve(capacity, index - 1, bounds[index - 2]));
        return memo[index][capacity];
    }


public:
    BoundedKnapsack(const int capacity, const std::vector<int>& weights,
                    const std::vector<int>& bonuses, const std::vector<int>& bounds)
        : capacity(capacity), weights(weights), bonuses(bonuses), bounds(bounds),
          memo(weights.size() + 1, std::vector<int>(capacity + 1, -1))
    {
        if (weights.empty()) {
            memo[0][capacity] = 0;
        } else {
            solve(capacity, weights.size(), bounds[weights.size() - 1]);
        }
    }

    int get_max_knapsack_bonus() const {
        return memo[weights.size()][capacity];
    }
};

#endif // BOUNDEDKNAPSACK_H
