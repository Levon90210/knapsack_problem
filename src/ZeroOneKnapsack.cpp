#include <iostream>
#include "ZeroOneKnapsack.h"

int main() {
    const std::vector<int> weights = {2, 3, 4, 5};
    const std::vector<int> bonuses = {3, 4, 5, 6};
    constexpr int capacity = 10;

    std::cout
         << "Max Knapsack Bonus: "
         << ZeroOneKnapsack(capacity, weights, bonuses).get_max_knapsack_bonus()
         << std::endl;
    return 0;
}
