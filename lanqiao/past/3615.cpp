//
// Created by 沙枭 on 2024/4/25.
//
#include <iostream>
#include <queue>
#define ll long long
using namespace std;

struct Node {
  ll data;
  ll index;
  ll del;
  Node* pre;
  Node* next;
  Node(ll d, ll i, Node* p, Node* n): data(d), index(i), del(0), pre(p), next(n) {};
  Node(ll d, Node* n): data(d), index(n->index), del(0), pre(n->pre), next(n->next) {};
};
using Link = Node*;
Link l = new Node(0, -5, nullptr, nullptr);
Node* r = l;
int n, x, m;
auto cmp = [](Node* a, Node* b) {return
    a->data == b->data ? a->index < b->index : a->data > b->data;};
priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
struct node {
  int value, index;
  bool operator<(const node &c) const {
      if (value != c.value) return value > c.value;//小根堆写法
      return index > c.index;//题目要求，数值相等的情况下，优先选择下标靠前的
  }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    while (n--) {
        cin >> m;
        Node* s = new Node(m, n, r, nullptr);
        r->next = s;
        r = s;
        pq.push(s);
    }
    while (x--) {
        while (pq.top()->del) {
            pq.pop();
        }
        Node* p = pq.top();
        p->del = 1;
        if (p->pre != l) {
            Node* s = new Node(p->pre->data + p->data, p->pre);
            p->pre->del = 1;
            p->pre = s;
            s->pre->next = s;
            s->next = p->next;
            if (p->next) p->next->pre = s;
            pq.push(s);
        }
        if (p->next) {
            Node* s = new Node(p->next->data + p->data, p->next);
            p->next->del = 1;
            p->pre->next = s;
            s->pre = p->pre;
            if (s->next) s->next->pre = s;
            pq.push(s);
        }
        
//        Node *cur = l->next;
//        while (cur) {
//            cout << cur->data << " ";
//            cur = cur->next;
//        }
//        cout << endl;
        delete p;
    }
//    Node* cur = l->next;
//    while (cur) {
//        cout << cur->data << " ";
//        cur = cur->next;
//    }
    return 0;
}
/*5 3
2 4 2 8 7*/