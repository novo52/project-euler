#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int primes_found = 2;
    int last_prime_found;
    for (int i=1; primes_found < 10001; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0)
                break;
            else if (j + 1 > sqrt(i)) {
                primes_found++;
                last_prime_found = i;
                cout << "prime " << primes_found << ": " << i << endl;
            }
        }
    }

    return last_prime_found;
}


