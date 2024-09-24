//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"

using namespace std;

int main() {
  int n;
  while (cin >> n && n > 0) {
    auto *hh = new int[n];
    for (int i = 0; i < n; ++i) {
      cin >> hh[i];
    }
    int max = hh[0];
    for (int i = 0; i < n; ++i) {
      if (hh[i] > max)
        max = hh[i];
    }
    while (true) {
      bool flag = true;
      for (int i = 0; i < n; ++i) {
        if (max % hh[i] != 0) {
          flag = false;
          break;
        }
      }
      if (flag)
        break;
      ++max;
    }
    cout << max << endl;

    delete[] hh;
  }
  return 0;
}