#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> names;

int main() {
    ifstream file("[22D1] Names.txt");
    string scratch;
    while (getline(file, scratch, ',')) {
        names.push_back(scratch.substr(1, scratch.length() - 2));
    }
    file.close();

    sort(names.begin(), names.end());

    int total_score = 0;
    for (int i = 0; i < names.size(); i++) {
        int score = 0;
        for (int j = 0; j < names[i].length(); j++) {
            score += names[i][j] - 'A' + 1;
        }
        total_score += score * (i + 1);
    }
    cout << total_score;
}


