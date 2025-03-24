//
// Created by 沙枭 on 2024/5/2.
//
// L2-1 堆宝塔
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, m, mh, c;
    cin >> n;
    mh = c = 0;
    stack<int> a;
    stack<int> b;
    while (n--)
    {
        cin >> m;
        if (a.empty() || a.top() > m)
            a.push(m);
        else
        {
            if (b.empty() || b.top() < m)
                b.push(m);
            else
            {
                c++;
                if (a.size() > mh) mh = a.size();
                while (!a.empty())
                {
                    cout << a.top() << " ";
                    a.pop();
                }
                cout << endl;
                while (b.top() > m)
                {
                    a.push(b.top());
                    b.pop();
                }
            }
        }
    }
    while (!a.empty())
        {
            cout << a.top() << " ";
            a.pop();
        }
    cout << endl;
    while (!b.empty())
    {
        cout << b.top() << " ";
        b.pop();
    }
    cout << endl;
    cout << c << " " << mh;
}