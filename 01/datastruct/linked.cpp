//
// Created by supanx on 25-2-24.
//
//
#include <iostream>
#include <algorithm>
#include <string>
#define maxx 105
using namespace std;

typedef struct Node {
  string data;
  struct Node *next;
} Node, *Link;

//单链表 增删查改
// 增:
// 头插
Link head_insert(Link L, string s) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = s;
    n->next = L->next;
    L->next = n;
    return L;
}
// 尾插
Link tail_insert(Link L, string s) {
    Node* n =(Node*)malloc(sizeof(Node));
    n->data = s;
    n->next = NULL;
    Node* p = L;
    while (p->next) {
        p = p->next;
    }
    p->next = n;
    return L;
}

// 查 Use of undeclared identifier 'find_link'
Node* find_link(Link L, string s) {
    Node* p = L->next;
    while (p && p->data != s) {
        p = p->next;
    }
    return p;
}

// 中间插
Link mid_insert(Link L, string s, string k) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = s;
    Node* p = find_link(L, k);
    if (p) {
        n->next = p->next;
        p->next = n;
    }
    else cout << "" << k << " 不存在" << endl;
    return L;
}

// 改

// 删
Link dele(Link L, string s) {
    Node* pre = L;
    Node* q = L;
    while (q && q->data != s) {
        pre = q;
        q = q->next;
    }
    if (q) {
        pre->next = q->next;
        free(q);
        q = NULL;
    }
    else cout << "删除的 " << s << " 不存在" << endl;
    return L;
}

void show_link(Link L) {
    while (L && L->next) {
        L = L->next;
        cout << L->data << endl;
    }
}
int main() {
    Link L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    // 头插
    L = head_insert(L, "front");
    L = head_insert(L, "first");
    // 尾插
    L = tail_insert(L, "r");
    L = tail_insert(L, "last");
    // 中间插
    L = mid_insert(L, "mid", "front");
    L = mid_insert(L, "mi", "fro");
    // 删
    L = dele(L, "first");
    L = dele(L, "mi");
    L = dele(L, "r");
    
    show_link(L);
    
    return 0;
}

