//
// Created by supanx on 25-2-26.
//
#include <iostream>
#define maxs 11
using namespace std;

typedef struct StackNode {
  int data;
  struct StackNode* next;
} sstack, *link_stack;

// 判满
//int is_full(link_stack top) {
//    if ()
//}
// 判空
int is_emp(link_stack top) {
    if (top->next) return 0;
    return 1;
}
// 入栈
link_stack spush(link_stack top, int n) {
    sstack* s = (sstack*)malloc(sizeof(sstack));
    s->data = n;
    s->next = top->next;
    top->next = s;
    return top;
}
// 出栈
link_stack spop(link_stack top) {
    if (is_emp(top)) {
        cout << "is empty" << endl;
        return top;
    }
    sstack* p = top->next;
    top->next = p->next;
    free(p);
    p = NULL;
    return top;
}
void show(link_stack top) {
    while (top->next) {
        cout << top->next->data << endl;
        top = spop(top);
    }
}
int main() {
    link_stack top = (sstack*)malloc(sizeof(sstack) * maxs);
    top->next = NULL;
    top = spush(top, 5);
    top = spush(top, 6);
    top = spush(top, 8);
    top = spush(top, 7);
    
    top = spop(top);
    top = spop(top);
    
    show(top);
    
}