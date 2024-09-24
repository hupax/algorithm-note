//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
#include "string"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 0)
    {
        string line;
        auto* arr = new string[n];
        for (int i = 0; i < n; ++i) {
            cin >> line;
            arr[i] = line;
        }
        for (int i = 0; i < n; ++i) {
            int m = 0;
            for (int j = 0; j < arr[i].length(); ++j) {
                if ((int)arr[i][j] >= 48 && (int)arr[i][j] <= 57)
                {
                    m++;
                }
            }
            cout << m << endl;
        }

        delete[] arr;
    }
}
