//
// Created by 沙枭 on 2024/4/7.
//
#include "iostream"

using namespace std;

struct edge
{
    int key_value;
    edge *p_left;
    edge *p_right;
};

edge * insert(edge *p_tree, int key)     // 接受一棵树（edge）结构
{
//    基线条件
    if (p_tree == NULL)
    {
        edge *new_p_tree = new edge;
        new_p_tree->p_left = NULL;
        new_p_tree->p_right = NULL;
        new_p_tree->key_value = key;
        return new_p_tree;
    }
//    判读新节点插入左子树还是右子树中；
    if (key < p_tree->key_value)
    {
//        使用指向新树的指针代替p_tree->left;
        p_tree->p_left = insert(p_tree->p_left, key);
    } else
    {
        p_tree->p_right = insert(p_tree->p_right, key);
    }
    return p_tree;
}

edge* search(edge *p_tree, int key)
{
//    如果达到了空树，说明key不在树中；
    if (p_tree == NULL) return NULL;

    if (p_tree->key_value == key)
    {
        return p_tree;

    } else if (p_tree->key_value > key)
    {
//        这里能不能不return？
        return search(p_tree->p_left, key);
    } else
    {
        return search(p_tree->p_right, key);
    }
}

void destroy_tree(edge *p_tree)
{
    if (p_tree != NULL)
    {
        destroy_tree(p_tree->p_left);
        destroy_tree(p_tree->p_right);
        delete p_tree;
    }
}

int main()
{

}