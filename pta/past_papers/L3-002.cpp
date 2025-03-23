//
// Created by 沙枭 on 2024/4/18.
//
// L3-002 特殊堆栈
// Created on 2024/04/18.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, size_s, sst[100005];
string o;
vector<int> vec;
int main()
{
    size_s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> o;
        char c = o[1];
        if (c == 'o') {
            if (!size_s) {
                cout << "Invalid" << endl;
                continue;
            }
            cout << sst[size_s] << endl;
            vec.erase(find(vec.begin(), vec.end(), sst[size_s--]));
        }
        else if (c == 'u') {
            cin >> x;
            vec.insert(lower_bound(vec.begin(), vec.end(), x), x);
            sst[size_s + 1] = x;
            size_s++;
        }
        else {
            if (!size_s) {
                cout << "Invalid" << endl;
                continue;
            }
            int pe = (size_s & 1) ? (size_s + 1) / 2 : size_s / 2;
            cout << vec[pe - 1] << endl;
        }
        
    }
    return 0;
}