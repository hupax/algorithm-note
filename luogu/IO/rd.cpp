//
// Created by supanx on 25-3-22.
//
#include <bits/stdc++.h>
using namespace std;

//namespace IO {
const int BUF_SIZE = 1 << 20;
char ibuf[BUF_SIZE], * p1 = ibuf, * p2 = ibuf;
char obuf[BUF_SIZE], * p3 = obuf;

inline char gc() {
    if (p1 == p2)
        p2 = (p1 = ibuf)+fread(ibuf, 1, BUF_SIZE, stdin);
    return (p1 == p2) ? EOF : *p1++;
}

inline void pc(char c) {
    if (p3-obuf == BUF_SIZE) fwrite(obuf, 1, BUF_SIZE, stdout), p3 = obuf;
    *p3++ = c;
}

template<typename T>
inline void read(T &x) {
    x = 0;
    int f = 1;
    char ch = gc();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = gc();
    }
    while (isdigit(ch)) {
        x = x*10+(ch^48);
        ch = gc();
    }
    x *= f;
}

template<typename T>
inline void write(T x) {
    if (x < 0) x = -x, pc('-');
    static char stk[25];
    int top = 0;
    do {
        stk[top++] = x%10^48;
        x /= 10;
    }
    while (x);
    while (top) pc(stk[--top]);
}

inline void writeln(int x) {
    write(x), pc('\n');
}

inline void flush() {
    fwrite(obuf, 1, p3-obuf, stdout);
}
//} // namespace IO

// 用法：IO::read(x); IO::write(x); IO::writeln(x); IO::flush();
int main() {
//    using namespace IO;
    int n;
    read(n);         // 快读 n
    for (int i = 1; i <= n; ++i) {
        int x;
        read(x);     // 快读每个元素
        writeln(x);  // 快写每个元素（自动换行）
    }
    flush();         // 最后刷新输出缓存（非常重要）
    return 0;
}
