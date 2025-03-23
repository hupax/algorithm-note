当然,下面是几个使用`priority_queue`的经典示例:

1. 合并K个有序链表

题目描述:给你一个链表数组,每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中,返回合并后的链表。

示例代码:

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* r = &dummy;
        
        while (!pq.empty()) {
            auto edge = pq.top();
            pq.pop();
            
            r->next = edge;
            r = r->next;
            
            if (edge->next) {
                pq.push(edge->next);
            }
        }
        
        return dummy.next;
    }
};
```

2. 前K个高频元素

题目描述:给你一个整数数组`nums`和一个整数`x`
,请你返回其中出现频率前`x`高的元素。你可以按任意顺序返回答案。

示例代码:

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int x) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second < b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push(*it);
            if (pq.size() > x) {
                pq.pop();
            }
        }
        
        std::vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};
```

3. 数据流中的中位数

题目描述:
中位数是有序列表中间的数。如果列表长度是偶数,中位数则是中间两个数的平均值。设计一个支持以下两种操作的数据结构:

- void addNum(int num):从数据流中添加一个整数到数据结构中。
- double findMedian():返回目前所有元素的中位数。

示例代码:

```cpp
class MedianFinder {
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return m
```

以下是几个经典的 `priority_queue` 示例：

示例 1：实现一个最大堆

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 创建一个最大堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> max_heap;

    // 添加元素
    max_heap.push(10);
    max_heap.push(5);
    max_heap.push(15);
    max_heap.push(20);

    // 输出元素
    while (!max_heap.empty()) {
        std::cout << max_heap.top() << " ";
        max_heap.pop();
    }

    return 0;
}
```

示例 2：实现一个最小堆

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 创建一个最小堆
    std::priority_queue<int, std::vector<int>, std::less<int>> min_heap;

    // 添加元素
    min_heap.push(10);
    min_heap.push(5);
    min_heap.push(15);
    min_heap.push(20);

    // 输出元素
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }

    return 0;
}
```

示例 3：实现一个优先级队列

```cpp
#include <iostream>
#include <queue>
#include <vector>

struct Task {
    int priority;
    std::string task;
};

bool compareTask(const Task& a, const Task& b) {
    return a.priority < b.priority;
}

int main() {
    // 创建一个优先级队列
    std::priority_queue<Task, std::vector<Task>, decltype(compareTask)> priority_queue(compareTask);

    // 添加任务
    priority_queue.push({10, "Task 1"});
    priority_queue.push({5, "Task 2"});
    priority_queue.push({3, "Task 3"});

    // 处理任务
    while (!priority_queue.empty()) {
        Task current_task = priority_queue.top();
        std::cout << "处理任务：" << current_task.task << std::endl;
        priority_queue.pop();
    }

    return 0;
}
```

这些示例分别展示了如何实现一个最大堆、最小堆以及优先级队列。希望这些示例能够帮助您更好地理解 `priority_queue`
的用法。如果您有任何疑问，请随时提问。