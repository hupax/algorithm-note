//
// Created by 沙枭 on 24-5-19.
//
//7-24 树种统计
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
double n;
string line;
map<string, int> nma;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        nma[line]++;
    }
    cout << fixed << setprecision(4);
    for (auto &[k, v] : nma) {
        cout << k << " " << v / n * 100.0 << "%" << endl;
    }
}
