
#include <iostream>
#include <vector>

using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int n_permute_r(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int n_choose_r(int n, int r){
    return factorial(n) / (factorial(n - r) * factorial(r));
}

long long nth_lexicographic_permutation(int n, int k) {
    long long result = 0;

    std::vector<bool> k_values_used(262144);
    int previous_frame_size = n_permute_r(k, k);

    for(int digit = 0; digit < k; digit++) {
        int current_level_size = previous_frame_size / (k - digit);
        int index_within_level = n / current_level_size;

        // find index_within_level-th unused digit
        int digit_value;
        for(int i = 0, unused_k_value_index = 0; i < k; i++) {
            if (unused_k_value_index == index_within_level) digit_value = i;
            if (!k_values_used[i]) unused_k_value_index++;
        }

        // adjust frame size and offset
        k_values_used[digit_value] = true;
        previous_frame_size = current_level_size;
        n -= current_level_size * index_within_level;

        // append digit to result
        result *= 10;
        result += digit_value;
    }

    return result;
}

int main() {

    cout << nth_lexicographic_permutation(999999, 10);

}