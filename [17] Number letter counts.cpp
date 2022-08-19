#include <cmath>
#include <iostream>

using namespace std;
string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string tens[] = {"zeroty", "tenty", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                  "nineteen"};

int digitAt(int number, int digit) {
    return number / (int) std::pow(10, digit) % 10;
}

string writeString(int number) {
    const int length = (int) log10(number) + 1;
    string output;
    if (length == 4) output += "one thousand"; // One thousand
    int h = digitAt(number, 2);
    int t = digitAt(number, 1);
    int o = digitAt(number, 0);
    if (length >= 3 && h != 0) {
        output += ones[h] + " hundred"; // one-nine Hundred
    }
    if (length >= 2) {
        if (length >= 3 && (t != 0 || o != 0)) output += " and"; // And
        if (t > 1) output += " " + tens[t]; // twenty-ninety
        else if (t == 1) output += " " + teens[o]; // eleven-nineteen
    }
    if ((length == 1 || t != 1) && o != 0) output += " " + ones[o]; // one-nine
    return output;
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        string written = writeString(i);
        for (char j: written) if (isalpha(j)) sum++;
    }
    cout << sum;
}



