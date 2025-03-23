//
// Created by supanx on 25-3-15.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;
const int maxx = 2*1e5+5;
int n, ai;
int f[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int num[maxx];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num+n, [](int a, int b) {
      int x = 0, y = 0;
      int d = a, k = b;
      while (a > 0) {
          x += f[a%10];
          a /= 10;
      }
      while (b > 0) {
          y += f[b%10];
          b /= 10;
      }
      return x == y ? d < k : x < y;
    });
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    return 0;
}