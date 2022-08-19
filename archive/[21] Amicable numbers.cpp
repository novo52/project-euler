#include <iostream>

using namespace std;

int total = 0;

int sumOfProperDivisors(int number) {
    total++;
    if (number < 2) return 0;
    int sum = 0;
    for (int d = 2; d * d < number; d++) {
        if (number % d == 0) {
            sum += d;
            if (number / d != d) sum += number / d;
        }
    }
    return sum + 1;
}

int main() {
    int sum = 0;
    for (int a = 2; a < 10000; a++) {
        int b = sumOfProperDivisors(a);
        if (b > a && a == sumOfProperDivisors(b)) sum += a + b;
    }
    cout << sum << endl;
    cout << "called " << total << " times";
}


