//
// Created by supanx on 25-2-27.
//
#include <iostream>
#define maxs 6
using namespace std;
//int fib(int x) {
//    if (!x || x == 1) return 1;
//    return fib(x - 1) + fib(x - 2);
//}

// 存孩子节点
typedef struct ChildNode {
  int ci;
  struct ChildNode* next;
} ChNode;

struct Tree {
  char data;
  ChNode* first;
} t[105];

int size_tr = 0;

int find(char c) {
    for (int i = 0; i < size_tr; i++) {
        if (t[i].data == c) return i;
    }
//    return -1;
}
// 初始化
void init_tree(char root) {
    t[size_tr].data = root;
    t[size_tr].first = NULL;
    size_tr++;
}
void insert_t(char x, char fx) {
    t[size_tr].data = x;
    int fi = find(fx);
//    ChNode* s = (ChNode*)malloc(sizeof(ChNode));
    auto* s = new ChNode;
    s->ci = size_tr;
    s->next = t[fi].first;
    t[fi].first = s;
    size_tr++;
}
void get_f(char c) {
    for (int i = 0; i < size_tr; i++) {
        ChNode* p = t[i].first;
        int xi = find(c);
        while (p) {
            if (xi == p->ci) {
                cout << "f: " << t[i].data << endl;
                break;
            }
            p = p->next;
        }
    }
}
void get_child(char c) {
    ChNode* p = t[find(c)].first;
    while (p) {
        cout << "c: " << t[p->ci].data << endl;
        p = p->next;
    }
}
int main() {
    int n;
    char root;
    scanf("%d %c\n", &n, &root);
    init_tree(root);
    char x, fx;
    for (int i = 1; i < n; i++) {
        cin >> x >> fx;
        insert_t(x, fx);
    }
    
    cin >> x;
    get_f(x);
    get_child(x);
    
    return 0;
}