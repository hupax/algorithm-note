//
// Created by supanx on 25-2-28.
//
/*
#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct Node{
  int data;
  struct Node* pre;
  struct Node* next;
} Node, *Link;
unordered_map<int, Node*> mn;
int n, m, x;
char o;
int main() {
    cin >> n >> m;
    Node* l = (Node*)malloc(sizeof(Node));
    Node* r = l;
    l->pre = l->next = NULL;
    for (int i = 1; i <= n; i++) {
        Node* s = (Node*)malloc(sizeof(Node));
        s->data = i;
        s->pre = r;
        s->next = r->next;
        r->next = s;
        r = s;
        mn[i] = s;
    }
    for (int i = 1; i <= m; i++) {
        getchar();
        scanf("%c %d", &o, &x);
        mn[x]->pre->next = mn[x]->next;
        if (mn[x]->next) mn[x]->next->pre = mn[x]->pre;
        mn[x]->pre = o == 'L' ? l : r;
        mn[x]->next = o == 'R' ? NULL : l->next;
        if (o == 'L') {
            if (l->next) l->next->pre = mn[x];
            l->next = mn[x];
        }
        else {
            r->next = mn[x];
            r = mn[x];
        }
    }
    Node* ans = l->next;
    while (ans) {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}*/
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct Node {
  int data;
  struct Node *pre;
  struct Node *next;
} Node, *Link;
unordered_map<int, Node*> mk;
int n, m, x;
char o;
int main() {
    Link L = (Node *) malloc(sizeof(Node));
    L->pre = L->next = L;
    
    cin >> n >> m;
    n += 1;
    while (--n) {
        Node *s = (Node *) malloc(sizeof(Node));
        s->data = n;
        s->pre = L;
        s->next = L->next;
        L->next->pre = s;
        L->next = s;
        mk[n] = s;
    }
    while (m--) {
        getchar();
        scanf("%c %d", &o, &x);
        Node *p = mk[x];
//        Node *q = p;
        p->next->pre = p->pre;
        p->pre->next = p->next;
        p->pre = o == 'L' ? L : L->pre;
        p->next = o == 'R' ? L : L->next;
        if (o == 'L') {
            L->next->pre = p;
            L->next = p;
        }
        else {
            L->pre->next = p;
            L->pre = p;
        }
    }
    Node *ans = L->next;
    while (ans != L) {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}