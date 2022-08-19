#include <iostream>

using namespace std;

int main() {
    long long total = 0;
    for (int i = 2; i < 2000000; i++) {
        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) total += i;
    }
    cout << total;
}



