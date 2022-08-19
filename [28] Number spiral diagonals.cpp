#include <iostream>

using namespace std;

int main() {

    long long total = 1;
    const int layers = 501;

    for (int i = 2, n = 1; i < 2*layers; i += 2) {
        int add = 4*n + 10*i;
        total += add;
        n += 4 * i;
    }

    cout << total;

}