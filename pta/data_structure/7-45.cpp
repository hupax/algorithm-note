//
// Created by 沙枭 on 24-5-21.
//
// 7-45 航空公司VIP客户查询
#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int n, k, m, dst;
string id;
int main()
{
    cin >> n >> k;
    unordered_map<string, ll> vip;
    for (int i = 0; i < n; ++i) {
        cin >> id >> dst;
        vip[id] += dst < 500 ? 500 : dst;
    }
    cin >> m;
    while (m--) {
        cin >> id;
        if (vip.find(id) != vip.end()) {
            cout << vip[id] << endl;
        }
        else cout << "No Info" << endl;
    }
}
/*
输入样例:

4 500
330106199010080419 499
110108198403100012 15000
120104195510156021 800
330106199010080419 1
4
120104195510156021
110108198403100012
330106199010080419
33010619901008041x
输出样例:

800
15000
1000
No Info
 
 */