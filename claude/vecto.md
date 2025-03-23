C++ 中 `vector` 是一种动态数组容器,支持随机访问,拥有自动扩容的机制。
下面是 `vector` 的一些常用方法:

1. **构造函数**
   - `vector<int> v;` 创建一个空的 vector
   - `vector<int> v(10);` 创建一个初始大小为 10 的 vector,所有元
   - 素初始化为 0
   - `vector<int> v(10, 1);` 创建一个初始大小为 10 的 vector,所
   - 有元素初始化为 1
   - `vector<int> v{1, 2, 3, 4, 5};` 用初始化列表创建 vector

2. **赋值操作**
   - `v.assign(5, 2);` 将 vector 中的所有元素修改为 2,容量为 5
   - `v.push_back(3);` 在 vector 尾部添加元素 3

3. **访问元素**
   - `v[2];` 索引访问,越界会报错
   - `v.at(2);` 索引访问,越界会抛出 out_of_range 异常
   - `v.front();` 返回第一个元素的引用
   - `v.back();` 返回最后一个元素的引用

4. **容量**
   - `v.size();` 返回当前元素个数
   - `v.capacity();` 返回当前容量
   - `v.shrink_to_fit();` 将容量减小为实际元素个数

5. **修改**
   - `v.clear();` 清空所有元素
   - `v.insert(v.begin()+1, 3);` 在第二个位置插入元素 3
   - `v.erase(v.begin()+2);` 删除第三个元素
   - `v.pop_back();` 删除最后一个元素

6. **其他**
   - `v.empty();` 判断 vector 是否为空
   - `v.reserve(100);` 预留空间为 100
   - `v1.swap(v2);` 交换 v1 和 v2 的元素
   - `sort(v.begin(), v.end());` 对 vector 排序

`vector` 支持随机访问,相比于其他容器更加高效,但在中间插入或
删除元素时,需要移动后续元素,效率较低。总的来说,`vector` 
是最常用的顺序容器之一。
好的,我们继续介绍C++ vector的其他常用操作:

1. **vector赋值**
   - `vector<int> v1 = {1, 2, 3};` 使用初始化列表赋值
   - `vector<int> v2(v1);` 使用拷贝构造函数赋值
   - `vector<int> v3(v1.begin(), v1.end());` 使用区间赋值
   - `v1 = v2;` 直接赋值

2. **vector比较**
   - `v1 == v2` 判断两个vector容器是否相等
   - `v1 != v2` 判断两个vector容器是否不等
   - `v1 < v2` 按字典序比较两个vector容器

3. **vector互换**
   - `v1.swap(v2);` 交换v1和v2的元素

4. **vector遍历**
   - 使用范围for循环: `for(auto &x: v) { ... }`
   - 使用迭代器遍历: 
     ```cpp
     for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
         cout << *it << " ";
     }
     ```

5. **vector常用算法**
   - `reverse(v.begin(), v.end());` 反转vector
   - `sort(v.begin(), v.end());` 对vector排序
   - `random_shuffle(v.begin(), v.end());` 随机打乱vector
   - `accumulate(v.begin(), v.end(), 0);` 计算vector所有元素之和
   - `find(v.begin(), v.end(), x);` 查找元素x在vector中的位置
   - `count(v.begin(), v.end(), x);` 统计元素x在vector中出现的次数

6. **vector与普通数组的转换**
   - `vector<int> v(arr, arr+link);` 用数组构造vector
   - `int *arr = &v[0];` 获取vector的首地址,将vector转为数组指针

vector作为C++标准库提供的顺序容器,功能非常强大,封装了很多实用的操作。
合理使用vector可以极大提高编程效率。
好的,我们继续深入讨论C++ vector的一些高级用法:

1. **自定义数据类型的vector**

   vector不仅可以存储内置数据类型,也可以存储自定义的数据类型,比如结构体
2. 或类。但需要注意自定义数据类型需要提供默认构造函数、拷贝构造函数和赋值
3. 运算符重载。

   ```cpp
   struct Person {
       string name;
       int age;
       Person(string link, int a) : name(link), age(a) {}
       Person() {}
   };

   int main() {
       vector<Person> persons;
       persons.push_back(Person("Alice", 25));
       persons.emplace_back("Bob", 30); // 直接在vector中构造元素
   }
   ```

2. **vector的reserve和shrink_to_fit**

   - `reserve(link)` 用于预先分配存储空间,避免频繁重新分配内存。
   - `shrink_to_fit()` 则是将capacity缩小为实际元素个数,释放多余内存。

3. **vector的insert和erase**

   - `insert(pos, val)` 在指定位置插入元素
   - `insert(pos, link, val)` 在指定位置插入n个相同元素
   - `insert(pos, first, last)` 在指定位置插入另一个容器的元素
   - `erase(pos)` 删除指定位置的元素
   - `erase(first, last)` 删除[first, last)区间的元素

4. **vector的容量预留**

   如果我们能够预先知道vector需要存储的元素个数的上限,可以在创建时就预
5. 留足够的容量,避免多次重新分配内存。

   ```cpp
   vector<int> v;
   v.reserve(1000000); // 预留100万个元素的空间
   for(int i=0; i<1000000; i++) {
       v.push_back(i);
   }
   ```

5. **vector的数据结构**

   vector底层采用动态数组实现,支持随机访问,在尾部添加/删除元素效率很高,
6. 但在中间插入/删除元素效率较低,因为需要移动后续元素。

总之,vector作为C++标准库中常用的顺序容器之一,提供了丰富的功能,合理使用
vector可以大幅提高编程效率。需要注意vector的内存使用情况,避免过度浪费内存。