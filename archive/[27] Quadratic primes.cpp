#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

int quad_prime_run_size(int a, int b) {
    for(int n = 0; ; n++) {
        int result = n*n + a*n + b;
        if(!isPrime(abs(result))) return n;
    }
}


int main() {

    int max_run_size = 0;
    int max_coefficient_product = 0;
    for(int a = -1000; a <= 1000; a++) {
        for(int b = -1000; b <= 1000; b++) {
            int run_size = quad_prime_run_size(a, b);
            if(run_size > max_run_size) {
                cout << a << ", " << b << " with " << run_size << endl;
                max_run_size = run_size;
                max_coefficient_product = a * b;
            }
        }
    }

    cout << max_coefficient_product;
}