//
// Created by supanx on 25-3-14.
//
// 查找单链表倒数第 cnt 个节点
/* 思路
 * 双指针 间隔 cnt - 个节点
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* trainingPlan(ListNode* head, int cnt) {
    ListNode *l, *r;
    l = r = head;
    while (r) {
        if (cnt < 1) l = l->next;
        cnt--;
        r = r->next;
    }
    return l;
}

int main() {
    
    return 0;
}