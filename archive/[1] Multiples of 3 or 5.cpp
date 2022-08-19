#include <iostream>
#include <cmath>

using namespace std;

int sumOfMultiplesBelow(int multiple, int below) {
    int n = std::ceil((float) below / (float) multiple);
    return multiple * n * (n - 1) / 2;
}

int main() {
    cout << (sumOfMultiplesBelow(3, 1000) + sumOfMultiplesBelow(5, 1000) - sumOfMultiplesBelow(15, 1000));
}