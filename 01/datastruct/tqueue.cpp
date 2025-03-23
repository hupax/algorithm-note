//
// Created by supanx on 25-2-27.
//
#include <iostream>
#define maxs 6
using namespace std;

/*int* q;
int l, r, size_q;

// 左进左出
void insert_l(int x) {
    // 判满
    if (size_q == maxs) {
        cout << "full" << endl;
        return;
    }
    q[l] = x;
    l = (l+1) % maxs;
    size_q++;
}
void dele_l() {
    // 判空
    if (!size_q) {
        cout << "empty" << endl;
        return;
    }
    cout << q[(l - 1 + maxs) % maxs] << endl;
    l = (l - 1 + maxs) % maxs;
    size_q--;
}
// 右进右出
void insert_r(int x) {
    // 判满
    if (!(size_q - maxs)) {
        cout << "empty" << endl;
        return;
    }
    q[r] = x;
    r = (r - 1 + maxs) % maxs;
    size_q++;
}
void dele_r() {
    // 判空
    if (!size_q) {
        cout << "empty" << endl;
        return;
    }
    cout << q[(r + 1) % maxs] << endl;
    r = (r + 1) % maxs;
    size_q--;
}*/
typedef struct QNode{
  int data;
  struct QNode* pre;
  struct QNode* next;
}QNode, *LinkQ;

// 左进
LinkQ insert_l(LinkQ l, LinkQ *r, int k) {
    QNode* n = (QNode*)malloc(sizeof(QNode));
    n->data = k;
    n->pre = l;
    n->next = l->next;
    if (!l->next) *r = n;
    else l->next->pre = n;
    l->next = n;
    return l;
}

// 出
void dele(LinkQ l, LinkQ *r, int f) {
    // 判空
    if (!l->next) {
        cout << "empty" << endl;
        *r = l;
        return;
    }
    QNode* n = f ? l->next : *r;
    cout << n->data << endl;
    n->pre->next = n->next;
    if (n->next) n->next->pre = n->pre;
    else *r = n->pre;
    /*if (f) {
        link->pre->next = link->next;
        link->next->pre = link->pre;
    }
    else {
        link->pre->next = link->next;
        *r = link->pre;
    }*/
    free(n);
    n = NULL;
}
// 判空

// 右进
void insert_r(LinkQ *r, int k) {
    QNode* n = (QNode*)malloc(sizeof(QNode));
    n->data = k;
    n->pre = *r;
    n->next = (*r)->next;
    (*r)->next = n;
    *r = n;
}

int main() {
//    q = (int*)malloc(sizeof(int)*maxs);
//    l = 0;
//    r = maxs -1;
//    size_q = 0;
    LinkQ l = (QNode*)malloc(sizeof(QNode));
    LinkQ r = l;
    l->next = l->pre = NULL;
    
    
    insert_l(l, &r, 1);
    insert_l(l, &r, 2);
    insert_l(l, &r, 3);
    dele(l, &r, 0);
    dele(l, &r, 1);
    dele(l, &r, 1);
    insert_r(&r, 4);
    insert_r(&r, 5);
    insert_r(&r, 6);
    dele(l, &r, 0);
    dele(l, &r, 0);
    dele(l, &r, 0);
    insert_r(&r, 6);
    insert_r(&r, 6);
    dele(l, &r, 0);
    dele(l, &r, 1);
    return 0;
}
