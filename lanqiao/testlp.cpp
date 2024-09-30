//
// Created by 沙枭 on 2024/4/25.
//
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool flag = 0;
void reverse_word()
{
    string word;
    cin >> word;
}
int countOnesInBinary(int N)
{
    int count = 0;
    while (N > 0)
    {
        count += N & 1;  // 每次检查最低位是否为1
        N >>= 1;         // 右移一位
    }
    return count;
}

int main()
{
    double pi = 3.1592653589793;
    
    // 固定格式，保留小数点后2位
    
    // 恢复默认格式
    cout  << pi << endl;
    cout << /*fixed << */setprecision(2) << pi << endl;
    cout  << pi << endl;
    
    cout << 2020 % 1000 << endl;
    
    return cout << countOnesInBinary(2020) << endl, 0;
    
}