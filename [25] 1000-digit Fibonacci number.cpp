#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int fibonacci_lookup_limit = 10000;
long long *fibonacci_lookup = new long long[fibonacci_lookup_limit];


int digit_count(long long number) {
    if (number == 0) return 1;
    if(number < 0) number *= -1;

    return (int) log10(number) + 1;
}

long long fibonacci(long long f) {
    if(f < 1) return 0ll;
    if(f == 1) return 1ll;

    if(f < fibonacci_lookup_limit) {
        long long lookup = fibonacci_lookup[f];
        if(lookup == 0) { // If value not present, calculate it
            lookup = fibonacci(f-1) + fibonacci(f-2);
            fibonacci_lookup[f] = lookup;
        }
        return lookup;
    }

    return fibonacci(f-1) + fibonacci(f-2);
}


// OEIS A050815(999) + 1

int main() {

    for(int i = 0; i < fibonacci_lookup_limit; i++) fibonacci_lookup[i] = 0;

//    for(long long i = 0; i < 70; i++) {
//        long long fib = fibonacci(i);
//        cout << fib << endl;
//    }

    vector<int> lengths = {};

    int last_length = 0;
    int current_run_length = 0;
    for(long long i = 0; i < 70; i++) {
        const long long fib = fibonacci(i);
        const int length = digit_count(fib);

        if(last_length != length) {
            cout << current_run_length << " numbers " << last_length << " long." << endl;
            lengths.push_back(current_run_length);
            current_run_length = 0;
            last_length = length;
        }

        cout << fib << endl;
        current_run_length++;
    }

    for(int length : lengths) {
        cout << length << endl;
    }
}