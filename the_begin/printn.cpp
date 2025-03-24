//
// Created by 沙枭 on 2024/4/3.
//
#include "iostream"

using namespace std;

void printNum(int num)
{
    cout << num << " ";
    if (num > 0) printNum(num - 1);
    cout << num << " ";
}

int main()
{
    printNum(9);
}