//
// Created by 沙枭 on 2024/3/31.
//
// 指针声明
// <type> *<ptr_name>

#include "iostream"

using namespace std;

int main()
{
    int *p_int = NULL; // 初始化;
    int n;
    p_int = &n;
    cin >> n;
    cout << "n: " << n << endl;
    *p_int = 8;
    cout << "n: " << n << endl;
}