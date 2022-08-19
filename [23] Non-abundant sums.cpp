#include <iostream>

using namespace std;

const int max_num = 30000;
bool lookup_table[max_num] = {};

int sumOfProperDivisors(int number) {
    if (number < 2) return 0;
    int sum = 0;
    for (int d = 2; d * d <= number; d++) {
        if (number % d == 0) {
            sum += d;
            if (number / d != d) sum += number / d;
        }
    }
    return sum + 1;
}

bool has_abundant_sum(int i) {
    for(int j = 12; j < i; j++) {
        if(lookup_table[j] && lookup_table[i-j]) {
            return true;
        }
    }
    return false;
}

int main() {

    // precalculate lookup table
    for(int i = 0; i < max_num; i++) {
        lookup_table[i] = sumOfProperDivisors(i) > i;
    }

    // find total of all positive numbers which cannot be expressed as the sum of two abundant sums
    int total = 0;
    for(int i = 0; i < max_num; i++) if(!has_abundant_sum(i)) total += i;

    cout << total;

}