//
// Created by hupax on 25-4-6.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // 请在此输入您的代码
    bitset<8> b(6);
    for (int i=0; i<=7; i++) cout<<b[i];
    int a=b.count();
    cout<<endl<<a<<endl;
    vector<int> bits;
    int c=6;
    while (c) bits.push_back(c%2), c/=2;
    for (int &i:bits)cout<<i;
    return 0;
}