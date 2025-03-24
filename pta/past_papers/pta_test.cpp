//
// Created by supanx on 25-2-28.
//
#include <iostream>
#include <string>
using namespace std;
const int maxs = 70;
struct BNode {
  int isa;
  int left;
  int right;
  int typ;
} tre[maxs];
int n, x, l, r, f_root[maxs], isai; // f_root:找根节点
string s;
//int is_ai(int typ) {
//    return typ == 1 ? (s[isai++] - '0') && (s[isai++] - '0') ? 1 : 0 : typ == 2 ? (s[isai++] - '0')
//                || (s[isai++] - '0') ? 1 : 0 : (s[isai++] - '0') ? 0 : 1;
//}
int is_ai(int typ) {
    int a = s[isai++] - '0';
    if (typ == 3) return !a;  // 情变枝（NOT）翻转返回值
    int b = s[isai++] - '0';
    return (typ == 1) ? (a && b) : (a || b);
}
int is_aai(int typ, int le, int ri) {
    return typ == 1 ? le && ri : typ == 2 ? le || ri : !le;
}
//int in_order(int root) {
//    if (!root) return is_ai(tre[root].typ);
//    in_order(tre[root].left);
//    in_order(tre[root].right);
////    return tre[root].isa = tre[root].left == tre[root].right ?
////        : is_aai(tre[root].typ, tre[tre[root].left].isa, tre[tre[root].right].isa);
//    int rightVal = (tre[root].typ == 3) ? 0 : in_order(tre[root].right);
//    return tre[root].isa = is_aai(tre[root].typ, leftVal, rightVal);
//
//}
// ✅ 递归计算 `isa`
int in_order(int root) {
    if (root == 0) return is_ai(tre[root].typ);  // ✅ 叶子节点，读取值
    
    int leftVal = in_order(tre[root].left);
    int rightVal = (tre[root].typ == 3) ? 0 : in_order(tre[root].right);
    
    return tre[root].isa = is_aai(tre[root].typ, leftVal, rightVal);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> l;
        tre[i].typ = x;
        tre[i].left = l;
        f_root[l] = 1;
        if (x != 3) {
            cin >> r;
            tre[i].right = r;
            f_root[r] = 1;
        }
    }
    tre[0] = {0, 0, 0, 0};
    // 根
    int root;
    for (int i = 1; i <= n; i++) {
        if (!f_root[i]) root = i;
    }
    cin >> x;
    while (x--) {
        cin >> s;
        isai = 0;
        cout << (in_order(root) ? "Ai" : "BuAi") << endl;
    }
    return 0;
}

/*
6
2 6 3
1 0 0
3 4
2 0 0
3 0
1 5 2
5
11111
00000
11100
10011
01100

6
2 6 4
1 0 0
3 1
2 0 0
3 0
1 5 2
5
11111
00000
11100
10011
01100

 */