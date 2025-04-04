//
// Created by supanx on 25-3-4.
//
/*
 * 用树形结构来表示 (存储) 一个 集合, n 个集合 就是 n 棵树
 * 操作: 合并 查询
 * 1.合并: 把根节点相同的两个树(集合)合并为一棵树(集合): 把两个棵树其中的一颗作为根节点即可
 * 2.查询: 询问两个集合(树)是否为同一个集合(树): 判断根节点是否相同
 *
 * 实现:
 * 初始时每个元素的父亲是自己
 *
 * 通过孩子找到父亲,使用双亲表示法
 * f[x] = fx: f 的父亲为 fx
 * 根节点: 当f[x] = x 时, x为根节点
 *
 * 查找一个 x 的根节点最坏情况下时间复杂度为 O(n) 即树的层次(深度)
 *
 * 使用路径压缩优化: 在递归时就将 x 的父亲节点设置为 根节点 --> 深度变为 <= 4
 */

#include <iostream>
using namespace std;
int f[105];
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main() {
    
    return 0;
}
