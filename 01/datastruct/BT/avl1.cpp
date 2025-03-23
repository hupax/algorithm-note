//
// Created by supanx on 25-3-4.
//
// BST 二叉排序树 二叉搜索树 二叉查找树
/*
操作: 插入(建树) 查找 删除
插入: x
1.空树: 直接以 x 为根节点;
2.非空树: 根节点为 r , --> 在以 r 为根的 BST 上插入 x
            --> 比较 x 和 r->data 的大小;
            (1) x < r->data: x 应该插入在左子树 r->left 上 --> 在以 r->left 为根
                的左子树插入 x --> 递归
            (2) x > r->data: x 应该插入在左子树 r->right 上 --> 在以 r->right 为根
                的右子树插入 x --> 递归
            出口: 当 r 为 nullptr 时,说明找到了 x 插入的位置, 转化 --> 1

--非递归--
1.空树: x 直接作为根节点;
2.非空树:
 (1) 找到插入位置
 (2) 执行插入

删除: 要删除的节点 x (中序加括号)
1.x 的度为2:


*/
#include <iostream>
using namespace std;
struct BSTree {
  int data;
  BSTree* left;
  BSTree* right;
  BSTree(int d): data(d), left(nullptr), right(nullptr) {};
};
// 中序遍历:
void in_order(BSTree* root) {
    if (!root) return;
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
    
}
int n, x;

BSTree* bst_insert(BSTree* root) {
    if (!root)  {
        root = new BSTree(x);
        return root;
    }
    if (x < root->data) root->left = bst_insert(root->left);
    if (x > root->data) root->left = bst_insert(root->right);
    return root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 插入
    BSTree* root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = bst_insert(root);
    }
    in_order(root);
    return 0;
}