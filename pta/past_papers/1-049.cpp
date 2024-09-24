//
// Created by 沙枭 on 2024/4/10.
//
// L1-049 天梯赛座位分配
#include "iostream"
#include "queue"
#include "map"
#include "set"
#include "iomanip"

using namespace std;

int findKth(vector<int> &nums, int n)
{
    priority_queue<int> maxHeap;
    set<int> is(nums.begin(), nums.end());
    for (int i : is)
    {
        maxHeap.push(i);
        if (maxHeap.size() > n)
            maxHeap.pop();
    }
    return maxHeap.top();
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        map<int, int> im;
        map<int, int> im1;
        vector<int> iv(n);
        for (int &i: iv) {
            cin >> i;
            im[i] = im[i] + 1;
        }
        for (auto &[k, v] : im) cout << k << ": " << v << endl;
        int m = n;
        auto it = im.begin();
        int t;
        for (int i = 0; i < findKth(iv, n); ++i) {
            t = it->second;  // 1 1  3  3
            if (i < it->first)  // 2 2  3
            {
                if (m <= 2) im1[i] = 2;
                else
                    im1[i] = m;      // 9 9  5  5
                continue;
            }
            if (i < (++it)->first) // 0 0  3
            {
                if (m <= 2) im1[i] = 2;
                else
                {
                    m -= t;             // 0 0  8
                    if (m <= 2) im1[i] = 2;
                    else im1[i] = m;
                }
            }
        }
        cout << endl;
        for (auto &[k, v] : im1) cout << k + 1<< ": " << v << endl;
        for (int i = 1; i < n + 1; ++i) {
            int r = i;
            cout << "#" << i << endl;
            for (int j = 0; j < iv[i - 1]; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (k > 0) cout << " ";
                    cout << setw(2) << r;
                    r += im1[j];
                }
                cout << endl;
            }
        }
    }
}

























/*for (int i = 1; i < n + 1; ++i)
        {
            int t = i;
            cout << "#" << i << endl;
            for (int j = 0; j < iv[i - 1]; ++j)
            {
                for (int k = 0; k < 10; ++k) {
                    if (k == 0) cout << t;
                    else cout << " " << t;
                    if (j < findKth(iv, 1))
                        t += n;
                    else if (j >= findKth(iv, n - 2))
                        t += 2;
                    else if (j < findKth(iv, 2))
                        t += n - 1;
                    else if (j < findKth(iv, 3))
                        t += n - 2;
                    else if (j < findKth(iv, 4))
                        t += n - 3;
                    else if (j < findKth(iv, 5))
                        t += n - 4;
                    else if (j < findKth(iv, 6))
                        t += n - 5;
                    else if (j < findKth(iv, 7))
                        t += n - 6;
                    else if (j < findKth(iv, 8))
                        t += n - 7;
                    else if (j < findKth(iv, 9))
                        t += n - 8;
                }
                cout << endl;
            }
            m--;
        }*/