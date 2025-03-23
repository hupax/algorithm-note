//
// Created by supanx on 25-2-28.
//
#include <iostream>
#define maxs 100005
using namespace std;

struct Node {
  int data;
  int pre;
  int next;
} Link[maxs];
int l, r, n, a;
int main() {
    cin >> l >> n;
    while (n--) {
        cin >> a;
        cin >> Link[a].data >> Link[a].next;
    }
    int ns[maxs], idx = 0;
    int f = l;
    while (f != -1) {
        ns[idx++] = f;
        f = Link[f].next;
    }
    f = 0, r = idx - 1;
    while (f < r) {
        printf("%05d %d %05d\n", ns[r], Link[ns[r]].data, ns[f]);
        r--;
        printf("%05d %d ", ns[f], Link[ns[f]].data);
        if (f == r || f + 1 == r) cout << -1 << endl;
        else printf("%05d\n", ns[r]);
        f++;
    }
    return 0;
}
/*
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 4
00000 4 -1
00100 1 12309
33218 3 00000
12309 2 33218
 */