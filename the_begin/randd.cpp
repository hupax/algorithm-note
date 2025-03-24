//
// Created by 沙枭 on 2024/3/27.
//
// 如何生成指定范围的随机数呢

#include "iostream"
#include "ctime"
#include "cstdlib"

using namespace std;

// 声明函数原型
int randRange(int high, int low);

int main() {
    srand(time(NULL));
    int low = 5;
    int high = 8;
    for (int i = 0; i < 9; ++i) {
        cout << high << " ~ " << low <<
             "的随机数：\n" << randRange(high, low) << endl;
    }
}

// 定义一个生成指定范围的随机数的函数
int randRange(int high, int low) {
//    srand(time(NULL));
    return rand() % (high - low + 1) + low;
}


