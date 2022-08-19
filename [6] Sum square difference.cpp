#include <iostream>
#include <cmath>

using namespace std;

int sumOfNumbers(int n) {
    n++;
    return 1 * n * (n - 1) / 2;
}

int sumOfSquares(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

int main() {
    int sum = sumOfNumbers(100);
    cout << abs(sumOfSquares(100) - sum * sum);
}


