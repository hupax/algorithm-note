//
// Created by supanx on 25-2-28.
//
#include <iostream>
#include <iomanip>
#define maxs 100005
using namespace std;

struct Node {
  int data;
  int next;
} link[100005];
int cur, p, data_l, n, f_node, fd_node, f[10005];

void ans(int head) {
    while (head != -1) {
        cout << setw(5) << setfill('0') << head << " " << link[head].data << " ";
        if (link[head].next < 0) cout << -1;
        else cout << setw(5) << setfill('0') << link[head].next;
        cout << endl;
        head = link[head].next;
    }
}
int main() {
//    Node* link[10005] = (Node*)malloc(sizeof(Node));
    cin >> f_node >> n;
    while (n--) {
        cin >> cur;
        cin >> link[cur].data >> link[cur].next;
    }
    cur = f_node;
    int nex = link[cur].next;
    f[abs(link[cur].data)] = 1; // 第一个节点一定不重复
    fd_node = -1;
    int d_node = -1;
    while (nex != -1) {
        data_l = abs(link[nex].data);
        if (!f[data_l]) {
            f[data_l] = 1;
            cur = nex;
            nex = link[nex].next;
            continue;
        }
        int t = nex;
        link[cur].next = link[nex].next;
        nex = link[nex].next;
        if (fd_node < 0) fd_node = d_node = t;
        link[d_node].next = t;
        d_node = t;
        link[d_node].next = -1;
    }
    ans(f_node);
    ans(fd_node);
    return 0;
}

/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
 */