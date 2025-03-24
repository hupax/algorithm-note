//
// Created by supanx on 25-3-14.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *re_list(ListNode *cur, ListNode *pre) {
    if (cur->next == nullptr) {
        cur->next = pre;
        return cur;
    }
    ListNode *p = cur->next;
    cur->next = pre;
    pre = cur;
    cur = p;
    return re_list(cur, pre);
}
ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    return re_list(head, nullptr);
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 2; i <= 5; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    
//    ListNode *ans = head;
    ListNode *ans = reverseList(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}