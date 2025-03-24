//
// Created by 沙枭 on 2024/4/6.
//
// L1-023 输出GPLT
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

int main()
{
    string line;
    while (cin >> line && line.empty() == 0)
    {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        int G = line.find('G');
        int P = line.find('P');
        int L = line.find('L');
        int T = line.find('T');
        while (G != -1 || P != -1 || L != -1 || T != -1)
        {
            if (G != -1)
            {
                cout << line[G];
                line.erase(G, 1);
            }
            P = line.find('P');
            if (P != -1)
            {
                cout << line[P];
                line.erase(P, 1);
            }
            L = line.find('L');
            if (L != -1)
            {
                cout << line[L];
                line.erase(L, 1);
            }
            T = line.find('T');
            if (T != -1)
            {
                cout << line[T];
                line.erase(T, 1);
            }
            G = line.find('G');
            P = line.find('P');
            L = line.find('L');
            T = line.find('T');
        }
    }
    cout << endl;
}