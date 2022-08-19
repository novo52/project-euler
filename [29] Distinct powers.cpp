#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

// doesnt work
int main() {

    for(int i = 3; i < 10; i++) {
        vector<long> results = {};
        for (int a = 2; a <= i; a++) {
            for (int b = 2; b <= i; b++) {
                int result = pow(a, b);
                int duplicate = false;
                for (auto value: results) {
                    if (value == result) {
                        duplicate = true;
                        break;
                    }
                }
                if (duplicate) continue;
                results.push_back(result);
            }
        }
        cout << results.size() << endl;
    }


}