//
// Created by 沙枭 on 2024/4/4.
//
// L1-096 谁管谁叫爹
#include "iostream"
#include "string"

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string lineA, lineB;
        cin >> lineA >> lineB;
        int nA = stoi(lineA);
        int nB = stoi(lineB);
        int sA = 0;
        int sB = 0;
        for (char c : lineA)
        {
            sA += (int)(c - '0');
        }
        for (char c : lineB)
        {
            sB += (int)(c - '0');
        }
        bool a = nA % sB == 0;
        bool b = nB % sA == 0;
        if (a && b)
        {
            if (nA > nB) cout << "A";
            else cout << "B";
        }
        else if (a) cout << "A";
        else if (b) cout << "B";
        else
        {
            if (nA > nB) cout << "A";
            else cout << "B";
        }
        if (n) cout << endl;
    }
}