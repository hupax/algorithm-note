//
// Created by supanx on 25-2-27.
//
#include <iostream>
#define maxs 5
using namespace std;

/*typedef struct {
  int* data;
  int f, r;
}Squeue;

void en_queue(Squeue* q, int s) {
    // 判满
    if ((q->r + 1) % maxs == q->f) {
        cout << "full" << endl;
        return;
    }
    q->data[q->r] = s;
    q->r = (q->r + 1) % maxs;
}
void de_queue(Squeue* q) {
    // 判空
    if (q->r == q->f) {
        cout << "empty" << endl;
        return;
    }
    cout << q->data[q->f] << endl;
    q->f = (q->f + 1) % maxs;
}*/
typedef struct LinkQueue{
  int data;
  struct LinkQueue* next;
}que, *link_que;

void en_queue(link_que *r, int s) {
    LinkQueue* n = (LinkQueue*)malloc(sizeof(LinkQueue));
    n->data = s;
    n->next = (*r)->next;
    (*r)->next = n;
    *r = n;
}
void de_queue(link_que f, link_que *r) {
    // 判空
    if (!f->next) {
        cout << "empty" << endl;
        return;
    }
    LinkQueue *n = (LinkQueue*)malloc(sizeof(LinkQueue));
    n = f->next;
    if (!n->next) *r = f;
    cout << n->data << endl;
    f->next = n->next;
    free(n);
    n = NULL;
}
int main() {
//    Squeue q;
//    q.data = (int *) malloc(sizeof(int) * maxs);
//    q.f = q.r = 0;
    
    link_que f = (LinkQueue*)malloc(sizeof(LinkQueue));
    link_que r;
    r = f;
    f->next = NULL;
    
    
    en_queue(&r, 1);
    en_queue(&r, 2);
    en_queue(&r, 3);
    en_queue(&r, 4);
    en_queue(&r, 5);
    en_queue(&r, 6);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    en_queue(&r, 6);
    en_queue(&r, 4);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    en_queue(&r, 5);
    en_queue(&r, 6);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
    de_queue(f, &r);
}