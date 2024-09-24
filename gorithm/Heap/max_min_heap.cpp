//
// Created by 沙枭 on 2024/4/9.
//
// ** priority_queue ** (堆，优先级队列)
// 给定一个无序数组和一个整数K，找出第K大堆元素，和第N小的堆元素
// 应该使用小顶堆！
// 即使vector有相同的元素也能找出来

#include "iostream"
#include "queue"

using namespace std;

// 第K大
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (int i : nums)
    {
        minHeap.push(i);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    return minHeap.top();
}

// 第N小
int findNthSmallest(vector<int> &nums, int n)
{
    priority_queue<int> maxHeap;
    for (int i : nums)
    {
        maxHeap.push(i);
        if (maxHeap.size() > n)
            maxHeap.pop();
    }
    return maxHeap.top();
}

int main()
{
    vector<int> vInt = {3, 6, 3, 7, 3, 9, 7, 1, 2, 5, 8,};
    int k = 3;
    int n = 1;
    cout << "The " << k << "th largest element is: "
                << findKthLargest(vInt, k) << endl;
    cout << "The " << n << "th smallest element is: "
                << findNthSmallest(vInt, n) << endl;
    return 0;
}