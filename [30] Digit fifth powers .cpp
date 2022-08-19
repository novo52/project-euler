#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

int digitAt(long number, int digit) {
    return number / (long) std::pow(10, digit) % 10;
}

int digit_count(long long number) {
    if (number == 0) return 1;
    if(number < 0) number *= -1;

    return (int) log10(number) + 1;
}

int main() {

    int total = 0;
    for(int i = 2; i < 1000000; i++) {
        int sum = 0;
        for(int j = 0; j < digit_count(i); j++) {
            sum += pow(digitAt(i, j), 5);
        }

        if(sum == i) {
            total += i;
        }
    }

    cout << total;
}