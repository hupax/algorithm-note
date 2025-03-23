//
// Created by supanx on 25-3-5.
//
#include <iostream>
using namespace std;
struct BSTree {
  int data;
  BSTree* left;
  BSTree* right;
  BSTree(int d): data(d), left(nullptr), right(nullptr) {};
};
int n, k;
BSTree* insert_bst(BSTree* root) {
    if (!root) {
        root = new BSTree(k);
        return root;
    }
    if (k < root->data) root->left = insert_bst(root->left);
    else root->right = insert_bst(root->right);
    return root;
}
void post_order(BSTree* root) {
    if (!root) return;
    post_order(root->left);
    cout << root->data << " ";
    post_order(root->right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    BSTree* root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        root = insert_bst(root);
    }
    post_order(root);
    
    return 0;
}
/*
7高精度
8 6 5 7 10 8 11
 */