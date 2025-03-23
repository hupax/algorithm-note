//
// Created by 沙枭 on 2024/4/4.
//
#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int> vector1;
        for (int i = 2; i < sqrt(n) + 1; ++i) {
            if (n % i == 0) vector1.push_back(i);
        }
//        2 3 5 6 7 9 10 14 15 18 21    11个
        int max = 0;
        int pos = 0;
        if (vector1.empty()) cout << 1 << endl << n;
        else if (vector1.size() == 1) cout << 1 << endl << vector1[0];
        else
        {
            for (int i = 0; i < vector1.size() - 1; ++i) {
                int sum = vector1[i];
                int len = 1;
                for (int j = i; j < vector1.size() - 1; ++j) {
                    if (vector1[j] + 1 == vector1[j + 1] && n % (sum * vector1[j + 1]) == 0)
                    {
                        sum *= vector1[j + 1];
                        len++;
                    } else break;
                }
                if (max < len)
                {
                    max = len;
                    pos = i;
                }
            }
            cout << max << endl;
            for (int i = pos; i < pos + max; ++i) {
                if (i == pos) cout << vector1[i];
                else cout << "*" << vector1[i];
            }
            cout << endl;
        }
    }
}
/*    if (vector1[i] + 1 == vector1[i + 1] && )
    {
        int c = 0;
        int h = 0;
        for (int j = 0; j < vector1.size(); ++j) {
            if (j == i || j == i + 1) continue;

            int t = i + 1;
            int tem = vector1[i] * vector1[t];
            int p = tem * vector1[j];
            if (link % p == 0) h++;
            while (link % p == 0 && vector1[t] + 1 == vector1[t + 1])
            {
//                        cout << vector1[i] << "$$" << vector1[t] << "$$" << vector1[j] << endl;
                c++;
                p *= vector1[++t];
            }
        }
        cout << c << endl;
    }
    cout << endl;*/
