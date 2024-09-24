//
// Created by 沙枭 on 2024/4/5.
//
#include "iostream"
#include "string"
#include "chrono"
#include "ctime"

using namespace std;

int date(int y1, int m1, int d1, int y2, int m2, int d2);

int main()
{
    int m = date(2018, 11, 5, 2024, 4, 5);
    cout << m;
}

int date(int y1, int m1, int d1, int y2, int m2, int d2)
{
    tm date1{}, date2{};
    date1.tm_year = y1 - 1900;
    date1.tm_mon = m1 - 1;
    date1.tm_mday = d1;
    date2.tm_year = y2 - 1900;
    date2.tm_mon = m2 - 1;
    date2.tm_mday = d2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    auto diff = chrono::system_clock::from_time_t(time2) -
                            chrono::system_clock::from_time_t(time1);

    return chrono::duration_cast<chrono::hours>(diff).count() / 24;
}