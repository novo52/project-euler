#include <iostream>

const int coins = 8;
const int coin_values[coins] = {200, 100, 50, 20, 10, 5, 2, 1};
const int total_target_value = coin_values[0]; // largest coin

void recursive_count_combinations(int level, int& value, int* combination, int& valid_combinations_count) {
    for(combination[level] = 0; value < total_target_value; combination[level]++) {

        // Recurse unless at bottom level
        if(level < coins - 1) recursive_count_combinations(level + 1, value, combination, valid_combinations_count);

        value += coin_values[level];
    }

    // If it is 200 (valid combo), add it to the list
    if(value == total_target_value) valid_combinations_count++;

    // Tried all combinations for this level, reset this values and ascend
    value -= coin_values[level] * combination[level];
    combination[level] = 0;
}

int main() {

    int valid_combinations_count = 0;
    int total_value = 0;
    int coin_combination[coins];
    recursive_count_combinations(0, total_value, coin_combination, valid_combinations_count);

    std::cout << valid_combinations_count;
}