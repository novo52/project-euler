#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int number = 1;
    for (int i = 2; i <= 20; i++) {
        number = lcm(number, i);
    }
    cout << number;
}


