//
// Created by 沙枭 on 2024/4/4.
//
#include "vector"
#include "iostream"

using namespace std;

int printRra(vector<int> &arr, int left, int right, int target);

int main()
{
    vector<int> arr;
    for (int i = 0; i < 99; i += 2) {
        arr.push_back(i);
    }
//    auto *arr = new int[9];
//    for (int i = 0; i < 9; ++i) {
//        arr[i] = i;
//    }
// 012345678
    cout << printRra(arr, 0, arr.size() - 1, 34);


//    delete[] arr;
}

int printRra(vector<int> &arr, int left, int right, int target)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        } else if (arr[mid] > target)
        {
            return printRra(arr, left, mid - 1, target);
        } else
        {
            return printRra(arr, mid + 1, right, target);
        }
    }
    return -1;
}