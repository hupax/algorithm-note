//
// Created by supanx on 25-3-1.
//
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main() {
    int n = 500000;
    int arr[n];
    
    // `scanf()` 速度测试
    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t end = clock();
    cout << "scanf() 用时: " << double(end - start) / CLOCKS_PER_SEC << " 秒\n";
    
    // `cin`（优化后） 速度测试
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    start = clock();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    end = clock();
    cout << "cin(优化后) 用时: " << double(end - start) / CLOCKS_PER_SEC << " 秒\n";
    
    return 0;
}
