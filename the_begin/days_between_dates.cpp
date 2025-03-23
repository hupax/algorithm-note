//
// Created by 沙枭 on 24-11-11.
//

//
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
int julian_day(int year, int month, int day) {
    if (month <= 2) {
        year--;
        month += 12;
    }
    int jd = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month + 8) / 5 + day;
    return jd;
}

int days_between_dates(int year1, int month1, int day1, int year2, int month2, int day2) {
    int jd1 = julian_day(year1, month1, day1);
    int jd2 = julian_day(year2, month2, day2);
    return abs(jd1 - jd2);
}
int y, m, d, yy, mm, dd;
int date() {
    tm a = {}, b = {};
    a.tm_year = y - 1900;
    a.tm_mon = m - 1;
    a.tm_mday = d;
    
    b.tm_year = yy - 1900;
    b.tm_mon = mm - 1;
    b.tm_mday = dd;
    
    int seconds = difftime(mktime(&a), mktime(&b));
    int days = seconds / (24 * 60 * 60);
    
    return days;
}

int main() {
    y = 2024, m = 11, d = 11;
    yy = 2021, mm = 11, dd = 5;
    cout << date() << endl;
    int days_diff = days_between_dates(2024, 11, 11, 2021, 11, 5);
    cout << "两个日期相差的天数为: " << days_diff << endl;
}
