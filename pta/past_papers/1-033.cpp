//
// Created by 沙枭 on 2024/4/6.
//
// L1-033 出生年
#include "iostream"
#include "string"
#include "set"
#include "iomanip"

using namespace std;

int n_year(int year)
{
    set<char> cSet;
    string s_year = to_string(year);
    for (char c : s_year) cSet.insert(c);
    if (year < 1000) cSet.insert('0');
    return cSet.size();
}

int main()
{
    int year, n;
    cin >> year >> n;
    int t = year;

    if (n_year(year) == n)
    {
        cout << '0' << ' ' << setw(4) << setfill('0') << year << endl;
        return 0;
    }
    while (n_year(year) != n)
    {
        n_year(year++);
        if (n_year(year) == n)
        {
            cout << year - t << ' ' << setw(4) << setfill('0') << year << endl;
            return 0;
        }

    }
}