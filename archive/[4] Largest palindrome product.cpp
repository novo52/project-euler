#include <cmath>

using namespace std;

int digitAt(long number, int digit) {
    return number / (long) std::pow(10, digit) % 10;
}

bool isPalindromic(long number) {
    const int length = (int) log10(number) + 1;
    for (int i = 0; i < length / 2; i++) {
        if (digitAt(number, i) != digitAt(number, length - i - 1)) return false;
    }
    return true;
}

int main() {
    int largest = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int n = i * j;
            if (isPalindromic(n)) {
                if (n > largest) largest = n;
            }
        }
    }
    return largest;
}


