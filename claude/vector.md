好的,我很高兴为您介绍C++标准库中vector容器的常用方法。vector是一种动态
数组容器,提供了丰富的成员函数和操作方法。以下是一些常用的vector方法:

1. 构造函数:
```cpp
vector<int> v1;            // 默认构造函数,创建一个空vector
vector<int> v2(5);         // 创建一个包含5个默认值0的vector
vector<int> v3(5, 10);     // 创建一个包含5个值为10的vector
vector<int> v4(v2);        // 拷贝构造函数,创建一个与v2相同的vector
```

2. 访问元素:
```cpp
v1[0] = 10;                // 通过下标访问和修改元素
int x = v1.at(0);          // 使用at()函数安全地访问元素
int y = v1.front();        // 获取第一个元素
int z = v1.back();         // 获取最后一个元素
```

3. 增加和删除元素:
```cpp
v1.push_back(20);          // 在末尾添加一个元素
v1.pop_back();             // 删除最后一个元素
v1.insert(v1.begin() + 2, 30); // 在第三个位置插入元素30
v1.erase(v1.begin() + 2);  // 删除第三个元素
v1.clear();                // 清空vector
```

4. 容量管理:
```cpp
v1.size();                 // 返回vector中元素的个数
v1.capacity();             // 返回vector的容量
v1.reserve(100);           // 预分配100个元素的空间
v1.shrink_to_fit();        // 将capacity缩减到与size相同
```

5. 迭代器:
```cpp
for (auto it = v1.begin(); it != v1.end(); ++it) {
    cout << *it << " ";
}
for (auto x : v1) {         // 使用范围for循环遍历vector
    cout << x << " ";
}
```

6. 其他常用方法:
```cpp
v1.assign(5, 10);          // 将vector赋值为5个值为10的元素
v1.swap(v2);               // 交换v1和v2的元素
v1 == v2;                  // 比较两个vector是否相等
v1.begin(), v1.end();      // 获取vector的开始和结束迭代器
```

总之,vector提供了丰富的成员函数,可以方便地执行各种数组操作。掌握这些常
用
方法,可以帮助您更好地使用vector容器。如果您还有其他问题,欢迎随时询问。
好的,我继续为您介绍更多关于vector的常用方法。

7. 排序和搜索:
```cpp
#include <algorithm>

vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end());   // 对vector进行升序排序
reverse(v.begin(), v.end()); // 对vector进行降序排序

int target = 8;
auto it = find(v.begin(), v.end(), target); // 在vector中查找元素8
if (it != v.end()) {
    cout << "Found at index: " << distance(v.begin(), it) << endl;
} else {
    cout << "Not found" << endl;
}
```

8. 数学运算:
```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};

vector<int> sum(v1.size());
transform(v1.begin(), v1.end(), v2.begin(), sum.begin(), plus<int>());
// sum现在包含{5, 7, 9}

int product = accumulate(v1.begin(), v1.end(), 1, multiplies<int>());
// product现在为6
```

9. 二维vector:
```cpp
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

for (const auto& row : matrix) {
    for (int x : row) {
        cout << x << " ";
    }
    cout << endl;
}
```

10. 其他操作:
```cpp
v.emplace_back(10);        // 在末尾添加一个新元素,效率更高
v.emplace(v.begin() + 2, 20); // 在第三个位置插入一个新元素
v.data();                  // 获取指向vector第一个元素的原始指针
v.resize(10, 0);           // 将vector大小调整为10,新增元素初始化为0
```

总的来说,vector是C++标准库中非常实用的容器,提供了丰富的成员函数和操作方法。
掌握这些常用方法可以帮助您更好地使用vector来解决各种编程问题。如果您还有
任何其他问题,欢迎随时提出。
好的,我继续为您介绍更多关于C++标准库中vector容器的常用方法。

11. 比较和赋值:
```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};

// 比较两个vector
if (v1 == v2) {
    // 两个vector的元素完全相同
} else if (v1 < v2) {
    // v1的元素小于v2的元素
}

// 赋值操作
v2 = v1; // 将v1的元素复制到v2中
v2.assign(v1.begin(), v1.end()); // 将v1的元素赋值给v2
```

12. 子vector操作:
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// 获取子vector
vector<int> sub1(v.begin() + 1, v.begin() + 4); // sub1 = {2, 3, 4}
vector<int> sub2(v, 2, 3); // sub2 = {3, 4, 5}

// 删除子vector
v.erase(v.begin() + 1, v.begin() + 4); // v = {1, 5}
```

13. 多线程安全:
```cpp
#include <mutex>

vector<int> v;
std::mutex mtx;

void addElement(int x) {
    mtx.lock();
    v.push_back(x);
    mtx.unlock();
}

// 在多个线程中调用addElement()函数可以确保vector的线程安全
```

14. 自定义比较函数:
```cpp
struct CustomComparator {
    bool operator()(const int& a, const int& b) {
        return abs(a) < abs(b);
    }
};

vector<int> v = {-3, 1, -2, 4, 2};
sort(v.begin(), v.end(), CustomComparator());
// v现在为{2, -2, 1, -3, 4}
```

15. 其他高级用法:
- 使用initializer_list构造vector
- 利用vector实现栈和队列
- 使用vector实现邻接表表示图
- 在vector中存储自定义类对象

以上就是一些C++标准库vector容器的常用方法。希望这些介绍对您有所帮助。
如果您还有任何其他问题,欢迎随时提出。
