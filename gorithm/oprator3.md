好的,我继续为你介绍更多链表操作和技巧:

**11. 链表的插入排序**

除了归并排序,我们还可以使用插入排序的思路对链表进行排序。

```cpp
ListNode* insertionSortList(ListNode* l) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = l;
    ListNode* prev = dummy;
    while (curr != NULL) {
        ListNode* next = curr->next;
        prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
    return dummy->next;
}
```

**12. 链表元素交换**

交换链表中的两个节点,需要注意各种边界情况的处理。

```cpp
ListNode* swapNodes(ListNode* l, int val1, int val2) {
    ListNode* dummy = new ListNode(0);
    dummy->next = l;
    ListNode* prev1 = dummy, *prev2 = dummy, *node1 = nullptr, *node2 = nullptr;
    ListNode* curr = l;
    while (curr != nullptr) {
        if (curr->val == val1) {
            node1 = curr;
        } else if (curr->val == val2) {
            node2 = curr;
        }
        if (node1 != nullptr) prev1 = node1;
        if (node2 != nullptr) prev2 = node2;
        curr = curr->next;
    }
    if (node1 == nullptr || node2 == nullptr) return l;
    if (prev1->next == node2) {
        swap(node1->val, node2->val);
    } else if (prev2->next == node1) {
        swap(node1->val, node2->val);
    } else {
        swap(node1->val, node2->val);
        ListNode* temp = node2->next;
        prev2->next = node1;
        node2->next = node1->next;
        prev1->next = node2;
        node1->next = temp;
    }
    return dummy->next;
}
```

**13. 链表的回文判断**

判断一个链表是否是回文结构,可以使用反转链表的思路。

```cpp
ListNode* reverseList(ListNode* l) {
    ListNode* prev = nullptr;
    ListNode* curr = l;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode* l) {
    if (l == nullptr || l->next == nullptr) return true;
    ListNode* slow = l;
    ListNode* fast = l;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = reverseList(slow->next);
    slow->next = nullptr;
    ListNode* p1 = l;
    ListNode* p2 = secondHalf;
    while (p2 != nullptr) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
```

**14. 链表的旋转**

将链表向右旋转k个位置,其中k可以大于链表长度。

```cpp
ListNode* rotateRight(ListNode* l, int x) {
    if (l == nullptr || l->next == nullptr) return l;
    int len = 1;
    ListNode* r = l;
    while (r->next != nullptr

```
好的,我将举几个经典的链表题目作为竞赛的例子,帮助你练习使用链表的操作:

**1. 反转链表**

题目描述:给定一个单链表的头节点,反转该链表,并返回反转后的头节点。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

解题思路:
- 迭代法:通过改变节点指针的指向来反转链表
- 递归法:通过递归的方式反转链表

**2. 两数相加**

题目描述:给定两个非空链表,代表两个非负整数,将这两个数相加并以链表形式返回。

示例:
输入: (2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 0 -> 8
原因: 342 + 465 = 807

解题思路:
- 创建一个新链表存储结果
- 遍历两个链表,模拟手算相加的过程,注意进位

**3. 删除链表的倒数第N个节点**

题目描述:给定一个链表,删除链表的倒数第N个节点,并返回链表的头节点。

示例:
给定一个链表: 1->2->3->4->5, 和 link = 2.
当删除了倒数第二个节点后,链表变为 1->2->3->5.

解题思路:
- 使用快慢双指针,先让快指针走n步
- 然后快慢指针同时移动,当快指针到达末尾时,慢指针所在位置就是倒数第n个节点的前一个位置
- 删除倒数第n个节点

**4. 环形链表**

题目描述:给定一个链表,判断链表中是否有环。如果有环,返回环的入口节点,否则返回null。

示例:
输入: l = [3,2,0,-4], pos = 1 (链表中有一个环,其尾部连接到第二个节点)
输出: 返回节点引用的节点值为 2

解题思路:
- 使用快慢双指针,快指针每次移动两步,慢指针每次移动一步
- 如果有环,快慢指针一定会相遇
- 相遇后,将其中一个指针重新指向头节点,另一个从相遇点开始,两个指针每次移动一步,相遇的点就是环的入口

通过练习这些经典的链表题目,你可以加深对链表操作的理解,提高解决实际问题的能力,为将来的竞赛做好充分准备。
