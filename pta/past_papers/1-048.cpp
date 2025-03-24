//
// Created by 沙枭 on 2024/4/7.
//
// L1-048 矩阵A乘以B
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int r1, c1;
    cin >> r1 >> c1;
    int t;
    vector<vector<int>> vector1(r1, vector<int>(c1));
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c1; ++j)
        {
            cin >> t;
            vector1[i][j] = t;
        }
    }
    int r2, c2;
    cin >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "Error: " << c1 << " != " << r2 << endl;
        return 0;
    }
    vector<vector<int>> vector2(r2, vector<int>(c2));
    for (int i = 0; i < r2; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            cin >> t;
            vector2[i][j] = t;
        }
    }
    cout << r1 << " " << c2 << endl;
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            int sum = 0;
            for (int k = 0; k < c1; ++k)
            {
                sum += vector1[i][k] * vector2[k][j];
            }
            if (j == 0)
                cout << sum;
            else cout << " " << sum;
        }
        cout << endl;
    }
    vector1.clear();
    vector2.clear();
}
/*
2 3
1 2 3
4 5 6
3 4
7 8 9 0
-1 -2 -3 -4
5 6 7 8
2 4
20 22 24 16
53 58 63 28
 */