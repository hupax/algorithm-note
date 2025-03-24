//
// Created by supanx on 25-3-2.
//
#include <iostream>
using namespace std;
const int maxs = 105;

struct BST {
  char data;
  BST* left;
  BST* right;
  BST(char d) : data(d), left(nullptr), right(nullptr) {
  };
};

BST* find_b(BST* bst, char fa) {
    if (!bst || bst->data == fa) return bst;
    return find_b(bst->left, fa) ?: find_b(bst->right, fa);
}
// 前序
BST* find_bs(BST* bst, char k) {
    if (!bst || bst->data == k) return bst;
    find_bs(bst->left, k);
    cout << bst->data << " ";
    find_bs(bst->right, k);
    return nullptr;
}
void insert_b(BST* root, char k, char fa, int fg) {
    BST* p = find_b(root, fa);
    if (!p) {
        cout << "fa is nullptr" << endl;
        return;
    }
    BST* q = new BST(k);
    fg ? p->left = q : p->right = q;
}
// 栈遍历
BST* ss[maxs];
int stop = 0;
// 前序
void in_order(BST* root)
{
    BST* p = root;
    while (p != nullptr || stop) {
        if (p) {
            ss[stop++] = p;
            cout << p->data << ' ';
            p = p->left;
        }
        else {
            p = ss[--stop]->right;
        }
    }
}
void post_order(BST* root) {
    BST* p = root;
    BST* pre = nullptr;
    while (p != nullptr || stop) {
        if (p) {
            ss[stop++] = p;
//            cout << p->data << ' ';
            
            p = p->left;
        }
        else {
            if (ss[stop - 1]->right && ss[stop - 1]->right != pre) {
                p = ss[stop - 1]->right;
            }
            else {
                cout << ss[--stop]->data << " ";
                pre = ss[stop];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, fg;
    char k, fa;
    cin >> n >> k;
    BST* root = new BST(k);
    for (int i = 1; i < n; i++) {
        cin >> k >> fa >> fg;
        insert_b(root, k, fa, fg);
    }
//    find_bs(root, -1);
//    cout << "\n________" << endl;
//    BST* q[maxs];
//    int f = 0, r = 0;
//    q[r++] = root;
//    while (r != f) {
//        cout << q[f]->data << " ";
//        if (q[f]->left) {
//            q[r] = q[f]->left;
//            r = ++r % maxs;
//        }
//        if (q[f]->right) {
//            q[r] = q[f]->right;
//            r = ++r % maxs;
//        }
//        f = ++f % maxs;
//    }
// A   E F G K H   B C D
// F K G H E A C D B
//    in_order(root);
    post_order(root);
    delete root;
    return 0;
}
/*
7
1 0 1
2 1 1
3 1 0
4 2 1
5 2 0
6 3 1
7 3 0
9
A
B A 0
E A 1
C B 1
D C 0
F E 1
G F 0
H G 0
K G 1
 */