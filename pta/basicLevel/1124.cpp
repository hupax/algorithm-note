//
// Created by 沙枭 on 2024/4/14.
//
// 1124 最近的斐波那契数
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef long long ll;

ll f0 = 0, f1 = 1;
ll step = f0 + f1;
int findFei(ll n)
{
    if (step < n)
    {
        f0 = f1;
        f1 = step;
        step = f0 + f1;
        findFei(n);
    }
    return step;
}

int main()
{
    ll n;
    cin >> n;
    findFei(n);
    ll min = n - f1;
    if ((step - n) == min) cout << f1 << endl;
    else if ((step - n) < min) cout << step << endl;


    //cout << findFei(link) << endl;
    //cout << f1 << endl;

}