#include <iostream>
#include <valarray>

using namespace std;

bool isPrime(long long number) {
    for (long long i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int main() {

    const long long n = 600851475143;

    long long largest_prime_factor = 0;
    for (int factor = 2; factor < sqrt(n); factor++) {
        lldiv_t division = lldiv(n, factor); // division with remainder
        if (division.rem == 0) { // remainder is 0, factor is a factor of n
            if(factor > largest_prime_factor && isPrime(factor)) largest_prime_factor = factor;
            if(division.quot > largest_prime_factor && isPrime(division.quot)) largest_prime_factor = division.quot;
        }
    }
    cout << largest_prime_factor;
}
