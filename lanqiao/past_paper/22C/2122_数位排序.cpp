//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int maxx = 1e6 + 5;
int n, m;
struct A {
  int num;
  int val;
  bool operator<(const A &b) const {
      return val == b.val ? num < b.num : val < b.val;
  }
}A[maxx];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        A[i].num = i;
        int num = i;
        while (num) {
            A[i].val += num % 10;
            num /= 10;
        }
    }
    sort(A + 1, A + n + 1);
    cout << A[m].num;
    return 0;
}