#include <iostream>
#include <bitset>
using namespace std;
const int N = 3e6+5;
int n, ans[maxn], num[maxn], s[maxn], p = 0;
const int BUF_SIZE = 1 << 20;
char ibuf[BUF_SIZE], * p1 = ibuf, * p2 = ibuf;
char obuf[BUF_SIZE], * p3 = obuf;
inline char gc() {
//    if (p1 == p2)
//        p2 = (p1 = ibuf)+fread(ibuf, 1, BUF_SIZE, stdin);
//    return (p1 == p2) ? EOF : *p1++;
    return getchar();
}
inline int read() {
    char x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = gc();
    }
    while (isdigit(ch)) {
        x = (x<<1)+(x<<2)+(ch^48);
        ch = getchar();
    }
    return x *= f;
}
void write(int x) {
    if (x > 9) write(x/10);
    putchar(x%10+'0');
}
void wrc(int x) {
    if (x > 9) write(x/10);
    putchar(x%10+'0');
}
int main() {
//    int n;  enumerate
//    read(n);
//    cout << n;
//    cout << flush;
    string s="asdghjl";
    cout << s.find("sd")<<s.substr(0, 3);

    return 0;
}