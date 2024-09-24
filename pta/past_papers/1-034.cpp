//
// Created by 沙枭 on 2024/4/6.
//
// L1-034 点赞
#include "iostream"
#include "map"

using namespace std;

int main()
{
    map<int, int> map1;
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        int f;
        for (int i = 0; i < k; ++i) {
            cin >> f;
            map1[f] = map1[f] + 1;
        }
    }
    int maxK = 0;
    int maxV = 0;
    for (auto &[k, v] : map1)
        if (maxV < v) maxV = v;
    for (auto &[k, v] : map1)
        if (v == maxV && k > maxK) maxK = k;
    cout << maxK << " " << maxV << endl;
}