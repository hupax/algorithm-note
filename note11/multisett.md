`multiset` 是 C++ STL 中的一种 **有序容器**，它适用于 **频繁查找最小值并删除**
的情况，非常适合你的需求。以下是 `multiset` 的基本用法：

---

## **🔹 `multiset` 的特点**

1. **元素有序存储**（默认按 **升序** 排列）。
2. **允许重复元素**（不像 `set` 只存唯一值）。
3. **支持 `O(log N)` 插入、删除、查找最小值**。
4. **可以通过 `begin()` 访问最小值**。

---

## **🔹 `multiset` 的常用方法**

| **方法** | **作用** |
|----|----|
| `insert(x)` | 插入 `x`，会自动排序 |
| `erase(it)` | 删除迭代器 `it` 指向的元素 |
| `erase(x)` | 删除所有等于 `x` 的元素 |
| `find(x)` | 查找值为 `x` 的元素，返回迭代器 |
| `begin()` | 获取最小值的迭代器 |
| `rbegin()` | 获取最大值的迭代器 |
| `empty()` | 判断是否为空 |
| `size()` | 获取元素个数 |

---

## **🔹 基本示例**

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> s;  // 创建 multiset

    // 插入元素
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(2);  // multiset 允许重复元素

    // 遍历输出
    cout << "multiset 内容：";
    for (int x : s) cout << x << " ";
    cout << endl; // 输出: 2 2 5 8

    // 取最小值（最前面的元素）
    cout << "最小值: " << *s.begin() << endl; // 输出: 2

    // 删除最小值
    s.erase(s.begin());  // 删除第一个 2
    cout << "删除后: ";
    for (int x : s) cout << x << " ";
    cout << endl; // 输出: 2 5 8

    // 删除所有等于 2 的元素
    s.erase(2);
    cout << "删除所有 2: ";
    for (int x : s) cout << x << " ";
    cout << endl; // 输出: 5 8

    return 0;
}
```

---

## **🔹 用于存储 `Node*`（指针）**

在你的问题中，每个 `Node` 需要存到 `multiset`，按 `data` 排序：

```cpp
#include <iostream>
#include <set>

using namespace std;

struct Node {
    int data;
    Node(int d) : data(d) {}
};

// 比较函数，确保 multiset 以 data 进行排序
struct cmp {
    bool operator()(Node* a, Node* b) const {
        return a->data < b->data;
    }
};

int main() {
    multiset<Node*, cmp> s;  // multiset 存储 Node*

    Node* a = new Node(5);
    Node* b = new Node(2);
    Node* c = new Node(8);
    
    s.insert(a);
    s.insert(b);
    s.insert(c);

    cout << "最小值: " << (*s.begin())->data << endl;  // 输出: 2

    s.erase(s.begin());  // 删除最小值
    cout << "删除后最小值: " << (*s.begin())->data << endl; // 输出: 5

    // 释放内存
    delete a;
    delete b;
    delete c;

    return 0;
}
```

---

## **🔹 适用于你的代码**

在你的代码里，我们用 `multiset<Node*, cmp>` 维护 `Node*` 指针，并按照 `data` 排序：

```cpp
multiset<Node*, cmp> s;

// 插入
s.insert(新节点指针);

// 获取最小值
Node* p = *s.begin();

// 删除最小值
s.erase(s.begin());

// 删除某个已知节点
s.erase(指向该节点的迭代器);
```

---

## **总结**

- `multiset` **适合维护** **“最小值” 动态变化** 的情况。
- **支持重复元素**，所以不会丢失相同值。
- **`O(log N)` 复杂度**，比 `vector` **更高效**！
- **适合你的题目，确保删除顺序正确！** 🚀