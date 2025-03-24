//
// Created by supanx on 25-2-26.
//
#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  struct Node* pre;
  struct Node* next;
}Node, *LinkList;

// 双链表
// 头插
LinkList head_insert(LinkList L, int s) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = s;
    
    n->pre = L;
    n->next = L->next;
    L->next = n;
    if (n->next) {
        n->next->pre = n;
    }
    return L;
}
// 尾插
LinkList rear_insert(LinkList L, int s) {
    Node* n = (Node*)malloc(sizeof(Node));
    Node* p = L;
    while(p->next) {
        p = p->next;
    }
    n->data = s;
    
    n->pre = p;
    n->next = p->next;
    p->next = n;
    return L;
}
// 查
LinkList find_link(LinkList L, int k) {
    Node* p = L->next;
    while(p && p->data != k) {
        p = p->next;
    }
    return p;
}
//中间后插
LinkList mid_insert(LinkList L, int s, int k) {
    Node* p = find_link(L, k);
    if (!p) {
        cout << k << "不存在, 插入失败" << endl;
        return L;
    }
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = s;
    
    n->pre = p;
    n->next = p->next;
    p->next = n;
    if (n->next) {
        n->next->pre = n;
    }
    return L;
}

// 删
LinkList dele(LinkList L, int k) {
    if (!L->next) return L;
    
    Node* p = find_link(L, k);
    if (!p) {
        cout << k << "不存在, 删除失败" << endl;
        return L;
    }
    p->pre->next = p->next;
    if (p->next) {
        p->next->pre = p->pre;
    }
    free(p);
    p = NULL;
    return L;
}

void show(LinkList L) {
    Node* n = L;
    while (n->next) {
        n = n->next;
        cout << n->data << endl;
    }
    cout << endl;
}

int main() {
    LinkList L = (Node*)malloc(sizeof(Node));
    L->next = L->pre = NULL;
    
    L = head_insert(L, 1);
    L = head_insert(L, 2);
    L = head_insert(L, 3);
    show(L);
    // 尾插
    L = rear_insert(L, 4);
    L = rear_insert(L, 5);
    show(L);
    // 中间插
    L = mid_insert(L, 2, 6);
    L = mid_insert(L, 0, 3);
    show(L);
    // 删
    L = dele(L, 0);
    L = dele(L, 9);
    L = dele(L, 5);
    show(L);
    
    return 0;
}
/*
#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  struct Node *pre;
  struct Node *next;
} Node, *LinkList;

// 双链表
// 头插
LinkList head_insert(LinkList L, int s) {
    Node *link = (Node *) malloc(sizeof(Node));
    link->data = s;
    
    link->pre = L;
    link->next = L->next;
    L->next = link;
    link->next->pre = link;
    return L;
}
// 尾插
LinkList rear_insert(LinkList L, int s) {
    Node *link = (Node *) malloc(sizeof(Node));
    Node *p = L->next;
    while (p->next != L) {
        p = p->next;
    }
    link->data = s;
    
    link->pre = p;
    link->next = p->next;
    p->next = link;
    return L;
}
// 查
LinkList find_link(LinkList L, int x) {
    Node *p = L->next;
    while (p != L && p->data != x) {
        p = p->next;
    }
    return p;
}
//中间后插
LinkList mid_insert(LinkList L, int s, int x) {
    Node *p = find_link(L, x);
    if (p == L) {
        cout << x << "不存在, 插入失败" << endl;
        return L;
    }
    Node *link = (Node *) malloc(sizeof(Node));
    link->data = s;
    
    link->pre = p;
    link->next = p->next;
    p->next = link;
    link->next->pre = link;
    return L;
}

// 删
LinkList dele(LinkList L, int x) {
    if (L->next == L) return L;
    
    Node *p = find_link(L, x);
    if (p == L) {
        cout << x << "不存在, 删除失败" << endl;
        return L;
    }
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p);
    p = NULL;
    return L;
}

void show(LinkList L) {
    Node *link = L;
    while (link->next != L) {
        link = link->next;
        cout << link->data << endl;
    }
    cout << endl;
}

int main() {
    LinkList L = (Node *) malloc(sizeof(Node));
    L->next = L->pre = L;
    
    L = head_insert(L, 1);
    L = head_insert(L, 2);
    L = head_insert(L, 3);
    show(L);
    // 尾插
    L = rear_insert(L, 4);
    L = rear_insert(L, 5);
    show(L);
    // 中间插
    L = mid_insert(L, 2, 6);
    L = mid_insert(L, 0, 3);
    show(L);
    // 删…
    L = dele(L, 0);
    L = dele(L, 9);
    L = dele(L, 5);
    show(L);
    
    return 0;
}*/
