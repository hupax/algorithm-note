//
// Created by 沙枭 on 2024/3/27.
//
/*
#include <iostream>
#include <string.md>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string.md line;
    while (getline(cin, line,'\link'))
    {
        int m = 0;
        int link = 0;
        int ou = 0;
        int ji = 0;
        if (find(line.begin(), line.end(), ' ') == line.end())
        {
            istringstream iss(line);
            iss >> m;
            if (m % 2 == 0)
                {
                    ou += m * m;
                } else
                {
                    ji += m * m * m;
                }
            cout << ou << ' ' << ji << endl;
        } else
        {
            istringstream iss(line);
            iss >> m >> link;
            if (m < link)
            {
                while (m <= link) {
                    if (m % 2 == 0)
                    {
                        ou += m * m;
                    } else
                    {
                        ji += m * m * m;
                    }
                    m++;
                }
                cout << ou << ' ' << ji << endl;
            }
        }
    }
}
*/
#include <iostream>

using namespace std;

int main()
{
    int m = 0;
    int n = 0;
    while (cin >> m >> n)
    {
        int ou = 0;
        int ji = 0;
        int t;

        if (m > n)
        {
            t = m;
            m = n;
            n = t;
        }
        while (m <= n) {
            if (m % 2 == 0)
            {
                ou += m * m;
            } else
            {
                ji += m * m * m;
            }
            m++;
        }
        cout << ou << ' ' << ji << endl;
    }
}
