//
// Created by 沙枭 on 2024/4/10.
//
// 计算两个数的GCD和LCM
#include "iostream"
#include "algorithm"
//#include "bits/stdc++.h"
//#include "numeric"

using namespace std;

//int gcd(int a, int b)
//{
//    return b == 0 ? a : gcd(b, a % b);
//}
//inline int gcd(int a, int b) {
//    return !b?a:(b, a%b);
//}
inline int gcd(int a, int b) {
    return !b?a:gcd(b, a%b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    cout<< "GCD: " << g << endl;
    // 先将a转为long long，因为a*b可能溢出
    int l = static_cast<long long>(a) * b / gcd(a, b);
    cout << "LCM: " << l << endl;
}
/*

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

这个函数使用了条件运算符 `?:` 来实现递归。它的逻辑如下:

1. 如果 `b` 等于 0,则返回 `a`,因为当一个数为 0 时,另一个数就是它们的最大公约数。
2. 如果 `b` 不等于 0,则递归调用 `gcd` 函数,将 `b` 作为第一个参数,将 `a % b` 作为第二个参数。

这个递归过程会一直继续,直到 `b` 等于 0 为止。每次递归调用时,`a` 和 `b` 的值都会发生变化:
- `a` 的值变为上一次递归调用的 `b`。
- `b` 的值变为上一次递归调用的 `a % b`。

通过这样的递归调用,`gcd` 函数最终会找到 `a` 和 `b` 的最大公约数并返回。

这种递归实现的最大公约数算法称为欧几里得算法(Euclidean algorithm)或辗转相除法。它基于以下原理:
- 如果 `a` 可以被 `b` 整除,那么 `b` 就是它们的最大公约数。
- 如果 `a` 不能被 `b` 整除,那么 `a` 和 `b` 的最大公约数等于 `b` 和 `a % b` 的最大公约数。

通过递归地应用这个原理,最终可以得到 `a` 和 `b` 的最大公约数。

所以,在你给出的代码中,`gcd` 函数确实是一个递归函数,它使用递归的方式高效地计算了两个数的最大公约数。*/