//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
//#include "vector"

using namespace std;

/*
int main()
{
    int n;
    while (cin >> n && n <=100)
    {
        int m;
        cin >> m;
        if (m == 0 && n == 0) break;
        std::vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] < m && arr[i+1] > m)
            {
                arr.insert(arr.begin() + i + 1, m);
            }
        }
        for (int i = 0; i < n + 1; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}
*/
/*
int main()
{
    int n;
    while (cin >> n && n <=100)
    {
        int m;
        cin >> m;
        if (m == 0 && n == 0) break;
        auto* arr = new int[n];
        auto* brr = new int[n + 1];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int flag = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] < m && arr[i+1] > m)
            {
                break;
            }
            ++flag;
        }
        for (int i = 0; i < n + 1; ++i) {
            if (i == flag + 1)
            {
                brr[i] = m;
                continue;
            }
            brr[i] = arr[i - 1];
        }
        for (int i = 0; i < n + 1; ++i) {
            cout << brr[i] << ' ';
        }
        cout << endl;

        delete[] arr;
        delete[] brr;
    }
}
*/
int main() {
    int n;
    while (cin >> n && n <= 100) {
        int m;
        cin >> m;
        if (m == 0 && n == 0) break;

        ++n;
        auto *arr = new int[n];
        arr[0] = m;
        for (int i = 1; i < n; ++i) {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;

        delete[] arr;
    }
}
