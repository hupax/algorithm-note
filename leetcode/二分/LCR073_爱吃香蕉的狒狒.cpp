//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int check(int mid, vector<int> &piles, int h) {
    int cot=0;
    for (auto &it:piles) {
        cot+=it/mid;
        if (it%mid) cot++;
    }
    return cot<=h;
}

int minEatingSpeed(vector<int> &piles, int h) {
    int l=1, r=1, mid, ans;
    for (auto &it:piles) r=max(r, it);
    while (l<=r) {
        mid=(l+r)>>1;
        if (check(mid, piles, h)) {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

int main() {
    
    return 0;
}