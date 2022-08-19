#include <iostream>

using namespace std;

int month_lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_month_lengths[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int total_sundays = 0;
    int day_of_the_week = 1;
    for (int y = 1901; y <= 2000; y++) { // /4 = leap, /100 = not leap, /400 = leap
        int (&lengths)[12] = (y % 4 == 0) ? ((y % 400 || y % 100 != 0) ? leap_month_lengths : month_lengths)
                                          : month_lengths;
        for (int m = 0; m < 12; m++) {
            for (int d = 1; d <= lengths[m]; d++) {
                day_of_the_week++;
                if (day_of_the_week % 7 == 0 && d == 1) total_sundays++;
            }
        }
    }
    cout << total_sundays;
}



