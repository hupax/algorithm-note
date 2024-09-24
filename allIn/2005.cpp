//
// Created by 沙枭 on 2024/3/26.
//
/*#include "iostream"
#include "string.md"

using namespace std;

int main()
{
    string.md year;
    string.md moth;
    string.md day;
    while (getline(cin,year,'/') &&
                getline(cin,moth,'/') &&
                    cin >> day)
    {
        int num = 0;
        int y = stoi(year);
        int m = stoi(moth);
        int d = stoi(day);
        m--;
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 && m > 1)
        {
            num += 1;
        }
        for (; m > 0; m--)
        {
            if (m <=7)
            {
                if (m % 2 == 0)
                {
                    if (m == 2)
                    {
                        num += 28;
                    } else
                    {
                        num += 30;
                    }
                } else
                {
                    num += 31;
                }
            } else
            {
                if (m % 2 == 0)
                {
                    num += 31;
                } else
                {
                    num += 30;
                }
            }
        }
        cout << num + d << endl;
    }
    return 0;
}*/

// ac:
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string year;
    string moth;
    string day;
    while (getline(cin, year, '/') &&
           getline(cin, moth, '/') &&
           cin >> day) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int y = stoi(year);
        int m = stoi(moth);
        int d = stoi(day);
        // Check if it's a leap year
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            daysInMonth[1] = 29;
        }

        // Calculate the day of the year
        int dayOfYear = d;
        for (int i = 0; i < m - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }

        std::cout << dayOfYear << std::endl;
    }
    return 0;
}


