//
// Created by supanx on 25-3-22.
// 给定一个整数N，1<=N<=1e18，和K，1<=K<=50，求1 到 N 中有多少个数满足其二进制表示中恰好有 K 个 1
#include <iostream>
#include <vector>
#include <algorithm>
#define foi(x, y) for (int i=x; i<=y; i++)
#define foj(x, y) for (int j=x; j<=y; j++)
using namespace std;
using ll=long long;
const int N=20;
ll C[70][70];
inline void initC() { // 预处理组合数 C[n][k] 杨辉三角
    C[0][0]=1;
    foi(1, 65) {
        C[i][0]=1;
        foj(1, i) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
//    foi(1, 65) {
//        foj(1, i) cout << C[i][j]<< " ";
//        cout << endl;
//    }
}
ll n, k;
vector<int> bits;
int main() {
    initC();
    cin>>n>>k;
    while (n) bits.push_back(n%2), n/=2;
    reverse(bits.begin(), bits.end());
    // 13 --> 1101
    ll ans=0;
    int cnt=0, res; // cnt记录前面有多少个 1, 后面能放 1 的个数为 k-cnt
    foi(0, bits.size()-1) {
        if (bits[i]) { // 如果当前位是 1, 可以把他变为 0, 那么后面剩余的位就可以任选,不会超过 n
            res=bits.size()-i-1;
//            cout << res << " " << k-cnt << endl;
            if (k>=cnt) ans+=C[res][k-cnt];
            else break;
            cnt++;
        }
    }
    if (cnt==k) ans++;
    cout<<ans;
    
    return 0;
}

// 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
// 3+2+1
// 6
