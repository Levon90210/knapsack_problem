#include <iostream>
#include "BoundedKnapsack.h"

int main() {
    const std::vector<int> weights = {2, 3, 4, 5};
    const std::vector<int> bonuses = {3, 4, 5, 6};
    const std::vector<int> bounds = {3, 2, 1, 4};
    constexpr int capacity = 10;

    std::cout
         << "Max Knapsack Bonus: "
         << BoundedKnapsack(capacity, weights, bonuses, bounds).get_max_knapsack_bonus()
         << std::endl;
    return 0;
}