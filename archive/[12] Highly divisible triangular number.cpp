#include <iostream>

using namespace std;

int numOfDivisors(long long number) {
    int count = 0;
    for (long long d = 2; d * d < number; d++) {
        if (number % d == 0) {
            count++;
            if (number / d != d) count++;
        }
    }
    return count + 2;
}

int main() {
    long long triangle_number = 0;
    for (long i = 0; true; i++) {
        triangle_number += i;
        if (numOfDivisors(triangle_number) > 500) break;
    }
    cout << triangle_number;
}



