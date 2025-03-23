//
// Created by 沙枭 on 2024/3/31.
//
#include "iostream"

using namespace std;

void swap1(int x, int y)
{
    int t = x;
    x = y;
    y = t;
}
// 指针
void swap2(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
// 引用
void swap3(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}
int main()
{
    int x = 6;
    int y = 8;
    swap1(x, y);
    cout << "x: " << x << " y: " << y << endl;
    swap2(&x, &y);
    cout << "x: " << x << " y: " << y << endl;
    swap3(x,y);
    cout << "x: " << x << " y: " << y << endl;
}