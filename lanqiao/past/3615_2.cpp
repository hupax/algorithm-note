//
// Created by supanx on 25-3-1.
//
#include <iostream>
#include <queue>
#define ll long long
using namespace std;
const ll maxs = 1e6;
struct Node {
  ll data;
  ll index;
  bool operator<(const Node &b) const {
      return data == b.data ? index > b.index : data > b.data;}
};
int n, x;
ll num[maxs], pre[maxs], nex[maxs];
priority_queue<Node> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        pre[i] = i - 1;
        nex[i] = i + 1;
        q.push({num[i], i});
    }
    nex[n] = -1;
    while (x--) {
        int cur = q.top().data, idx = q.top().index; q.pop();
        if (num[idx] != cur) {x++; continue;}
        num[idx] = -1;
        if (pre[idx] != -1) {
            num[pre[idx]] += cur;
            nex[pre[idx]] = nex[idx];
            q.push({num[pre[idx]], pre[idx]});
        }
        if (nex[idx] != -1) {
            num[nex[idx]] += cur;
            pre[nex[idx]] = pre[idx];
            q.push({num[nex[idx]], nex[idx]});
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] == -1) continue;
        cout << num[i] << " ";
    }cout << endl;
    return 0;
}
/*5 3
2 4 2 8 7*/