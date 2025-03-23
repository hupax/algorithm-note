//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"
#include "random"

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(9,99);
    int array[66];
    for (int & i : array) {
        i = dis(gen);
    }
    for (const auto &item: array)
    {
        cout << item << endl;
    }
}