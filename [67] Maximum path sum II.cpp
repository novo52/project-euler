#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 100;

int pyramid[SIZE][SIZE];

int pyramid_sums[SIZE][SIZE];

int main() {

    // Read pyramid data from file
    ifstream file("[67D1] Pyramid.txt");
    string num;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x <= y; x++) {
            getline(file, num, x == y ? '\n' : ' ');
            pyramid[y][x] = stoi(num);
        }
    }
    file.close();

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x <= y; x++) {
            pyramid_sums[y][x] = pyramid[y][x];
            if (y == 0) continue;
            if (x == y) pyramid_sums[y][x] += pyramid_sums[y - 1][x - 1]; // Right edge
            else if (x == 0) pyramid_sums[y][x] += pyramid_sums[y - 1][x]; // Left edge
            else pyramid_sums[y][x] += max(pyramid_sums[y - 1][x - 1], pyramid_sums[y - 1][x]); // Left or right
        }
    }

    int largest_path = 0;
    for (int x = 0; x < SIZE; x++)
        if (pyramid_sums[SIZE - 1][x] > largest_path)
            largest_path = pyramid_sums[SIZE - 1][x];
    cout << largest_path;
}



