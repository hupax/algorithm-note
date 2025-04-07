//
// Created by supanx on 25-3-4.
//
/*
 * 求 a^n,
 * 1) 如果 n 是 2 大于等于 1 的某个整数次幂, 那么 a^n = a^2^n, 如 a^16 = a^2^4
 * 2) 任意 n 都可以写成 若干个 2^x 相加的形式 如 19 = 2^4 + 0 + 0 + 2^1 + 2^0
 * -->
 * a^19 = a^(2^4 + 0 + 0 + 2^1 + 2^0) = a^2^4 + 0 + 0 + a^2^1 + a^2^0
 *              将 n 转为 二进制, 19 = B(   1     0   0     1       1)
 * 所以可以在转换的过程中计算 a^19
 *
 */
#include <iostream>
using namespace std;

int main() {
    int a = 5, n = 19, res = 1;
    while (n != 0) {
        if (n % 2 != 0) res *= a; // 当 n 的该二进制位是 1 时
        n >>= 1;
        a *= a;     // 即对应二进制位时 res 要乘的值 刚好是 a^1 a^2 a^3 向上增长的
    }
    cout << res;
}
/*
 int main() {
    a, n, res; // 求 a^n
    while(n) {
        if (n&1) res*=a;
        n>>=1;
        a*=a;
    }
 
 }
 */