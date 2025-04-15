#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define inf INT_MAX
#define pii pair<int, int>
#define fo(a, b) for (int i=a; i<=b; i++)
#define gc getchar_unlocked()
using namespace std;
void read(int &x) {
    int f=1; char ch=gc;
    while (!isdigit(ch)) {
        if (ch=='-') f*=-1;
        ch=gc;
    }
    while (isdigit(ch)) {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc;
    }
    x*=f;
}
const int N=1e5+5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    
    return 0;
}