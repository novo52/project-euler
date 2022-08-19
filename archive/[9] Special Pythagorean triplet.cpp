#include <iostream>

using namespace std;

int main() {
    int result;
    for (int c = 1; c < 1000; c++) {
        for (int b = 1; b < c; b++) {
            int a = 1000 - b - c;
            if (a > b) continue;
            if (a * a + b * b == c * c) {
                result = a * b * c;
                goto broken;
            }
        }
    }
    broken:

    cout << result;
}



