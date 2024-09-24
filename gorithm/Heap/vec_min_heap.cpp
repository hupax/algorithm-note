//
// Created by 沙枭 on 24-5-9.
//
// vector实现小顶堆 pta 7-5
#include <iostream>
#include <vector>
using namespace std;

int n, m, x;
void heapify(vector<int> &heap, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = left + 1;
    if (left <= n && heap[left] < heap[smallest])
        smallest = left;
    if (right <= n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(heap, smallest);
    }
}
int main()
{
    cin >> n >> m;
    vector<int> heap(n + 1);
    vector<int> vis(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        cin >> heap[i];
        vis[i + 1] = heap[i];
    }
    for (int i = n / 2; i >= 1; --i)
        heapify(heap, i);
    swap(heap[n], heap[n - 1]);
//    for (auto &i : heap) cout << i << " ";
    cout << endl;
    while (m--)
    {
        cin >> x;
        while (x)
        {
            cout << heap[x];
            if (x != 1) cout << " ";
            x /= 2;
        }
        cout << endl;
    }
}
/*
输入样例:

5 1
46 23 26 24 10
5 4 3
输出样例:

24 23 10
46 23 10
26 10
 */