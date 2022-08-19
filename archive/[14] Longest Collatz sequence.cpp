#include <iostream>

using namespace std;

int main() {
    long long longest_i;
    int longest_l = 0;
    for (int i = 1; i < 1000000; i++) {
        long long n = i;
        int l = 1;
        for (; n != 1; l++) {
            if (n & 1) {
                n = 3 * n + 1;
            } else {
                n = n / 2;
            }
        }
        if (l > longest_l) {
            longest_l = l;
            longest_i = i;
        }
    }
    cout << longest_i;
}



