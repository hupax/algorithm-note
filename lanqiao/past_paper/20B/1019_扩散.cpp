//
// Created by hupax on 25-3-25.
//
/*

#include <iostream>
#include <queue>
#include <vector>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
const int maxn=2020+2020+2020+2020;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int ans=0, vis[maxn][maxn];
queue<pair<int, int>> q;
int main() {
    vis[2020][2020]=vis[4040][2031]=vis[2031][2034]=vis[4020][4020]=1;
    q.emplace(2020, 2020), q.emplace(4040, 2031);
    q.emplace(2031, 2034), q.emplace(4020, 4020);
    ans=4;
    for (int j=1; j<=2020; j++) {
        int siz=q.size();
        while (siz--) {
            auto [x, y]=q.front();
            q.pop();
            for (int i=0; i <= 3; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (vis[nx][ny]) continue;
                ans++;
                vis[nx][ny]=1;
                q.emplace(nx, ny);
            }
        }
    }
    cout<<ans;
    return 0;
}
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
using ll=long long;
const int OFFSET=4040+5;
inline ll encode(int x, int y) {
    return 1L*(x+OFFSET)*OFFSET*2+y+OFFSET;
}
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int ans=0;
vector<int> x, y;
vector<pair<int, int>> init={
    {0, 0}, {2020, 11}, {11, 14} , {2000, 2000}
};
queue<int> q;
unordered_set<ll> vis;
int main() {
    for (auto [xi, yi]:init) {
        x.push_back(xi);
        y.push_back(yi);
        vis.insert(encode(xi, yi));
        q.push(ans++);
    }
    fo(1, 2020) {
        int siz=q.size();
        while (siz--) {
            int cur=q.front(); q.pop();
            for (int j=0; j<4; j++) {
                int nx=x[cur]+dx[j], ny=y[cur]+dy[j];
                if (vis.count(encode(nx, ny))) continue;
                vis.insert(encode(nx, ny));
                x.push_back(nx);
                y.push_back(ny);
                q.push(ans++);
            }
        }
    }
    cout << ans; // 20312088
    return 0;
}

/*
小蓝在一张无限大的特殊画布上作画。
 这张画布可以看成一个方格图，每个格子可以用一 个二维的整数坐标表示。
 小蓝在画布上首先点了一下几个点： （0, 0）， （2020, 11）， （11,14）， （2000,2000）。
 只有这几个格子上有黑色，其它位置都是白色的。 每过一分钟，黑色就会扩散一点。
 具体的，如果一 个格子里面是黑色，它就会扩散到上、下、左、右 四个相邻的格子中，
 使得这四个格子也变成黑色 （如果原来就是黑色，则还是黑色）。
 请问，经过2020分钟后，画布上有多少个格子是 黑色的。
 
 */