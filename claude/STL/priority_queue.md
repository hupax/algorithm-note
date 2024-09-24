`priority_queue` 是 C++ STL 中的一个模板类，用于实现优先级队列。优先级队列是一种特殊的数据结构，其中元素根据优先级进行排序。`priority_queue` 使用二叉堆（heap）作为底层数据结构，可以实现最大堆（m-heap）或最小堆（min-heap）。

`priority_queue` 的特点：

1. 根据元素的优先级进行排序。最大堆会根据元素的大小排序，最小堆则根据元素的小さ。
2. 支持常数时间复杂度的插入和删除操作（`push` 和 `pop`）。
3. 支持获取队首元素的操作（`top`）。
4. Iterators（迭代器）支持随机访问。

`priority_queue` 的使用场景：

`priority_queue` 通常用于处理需要优先考虑某些元素的场景，如：

1. 任务调度：当有多个任务需要处理，但任务的执行时间或优先级不同时，可以使用`priority_queue`来优先执行最高优先级的任务。
2. 排序：当需要在不可能直接排序的情况下，按照某种优先级对元素进行排序时，可以使用`priority_queue`。
3. 最大/最小值：当需要快速获取最大或最小的元素时，可以使用`priority_queue`。

`priority_queue` 的参数：

1. `T`：模板类型参数，表示优先级队列中的元素类型。
2. `Container`：模板类型参数，表示存储元素的底层容器类型，默认为 `std::vector`。
3. `Compare`：模板类型参数，表示元素优先级的比较函数类型，默认为 `std::greater<T>`（最大堆）。如果使用最小堆，可以将其设置为 `std::less<T>`。

以下是一个使用`priority_queue`的示例：
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

    // 获取队首元素
    std::cout << "队首元素：" << max_heap.top() << std::endl;

    // 删除队首元素
    max_heap.pop();

    // 获取新的队首元素
    std::cout << "新的队首元素：" << max_heap.top() << std::endl;

    return 0;
}
```
在这个示例中，我们创建了一个最大堆，并添加了一些元素。然后，我们获取了队首元素并删除了它。最后，我们再次获取了新的队首元素。

希望这个简要的介绍对您有所帮助。如果您有任何疑问，请随时提问。

好的,让我为你详细介绍一下`priority_queue`。

`priority_queue`是C++标准库中的一个容器适配器,它提供了一个优先队列的实现。优先队列是一种抽象数据类型,它和普通队列的区别在于,优先队列中的每个元素都有一个优先级,优先级最高的元素会先被取出。

特点:
1. `priority_queue`默认使用`vector`作为底层容器,但也可以使用`deque`或者其他支持随机访问迭代器的容器。
2. `priority_queue`默认使用`less`作为比较函数,即默认为大顶堆。如果需要小顶堆,可以使用`greater`作为比较函数。
3. `priority_queue`不允许直接访问底层容器,只能通过队列顶端的元素来访问。
4. `priority_queue`的元素类型必须支持比较操作,即重载`<`或`>`运算符。

使用场景:
1. 任务调度系统:根据任务的优先级来安排任务的执行顺序。
2. Dijkstra算法:在图的最短路径算法中,使用优先队列来选择当前距离源节点最近的节点。
3. Huffman编码:在构建Huffman树时,使用优先队列来选择频率最低的两个节点进行合并。
4. Top K 问题:在海量数据中找出前K个最大或最小的元素。

常用函数:
- `push(val)`:将元素`val`插入到优先队列中。
- `top()`:返回优先队列中优先级最高的元素,即队首元素。
- `pop()`:删除优先队列中优先级最高的元素。
- `size()`:返回优先队列中元素的数量。
- `empty()`:检查优先队列是否为空,为空返回`true`,否则返回`false`。

声明方式:
```cpp
#include <queue>

// 默认为大顶堆
std::priority_queue<int> pq;

// 小顶堆
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

// 自定义比较函数
auto cmp = [](int a, int b) { return a > b; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
```

示例代码:
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

输出结果:
```
5 4 3 1 1
```

以上就是关于`priority_queue`的详细介绍,希望对你有所帮助。如果还有任何问题,欢迎随时问我。
