c++中map的常用方法包括:

1. 插入元素

- map[key] = value; //插入键值对
- map.insert(pair<key, value>(key, value)); //插入键值对
- map.insert(make_pair(key, value)); //插入键值对

2. 删除元素

- map.erase(key); //根据键删除键值对
- map.erase(iter); //根据迭代器删除键值对
- map.clear(); //清空所有元素

3. 查找元素

- map[key]; //根据键查找值
- map.find(key); //查找键key是否存在,存在返回该键的迭代器,
- 不存在返回map.end()
- map.count(key); //查找键key是否存在,存在返回1,不存在返回0

4. 遍历元素

- for(auto it : map) //基于范围的for循环遍历
- for(auto it = map.begin(); it != map.end(); ++it) 
- //通过迭代器遍历

5. 获取信息

- map.size(); //返回元素个数 
- map.empty(); //判断是否为空
- map.begin(); //返回指向第一个元素的迭代器
- map.end(); //返回末尾的迭代器
- map.key_comp(); //返回比较函数
- 这里再补充一些map的常用方法:

6. 修改元素

- map[key] = new_value; //直接通过key修改value

7. 比较函数

- map.key_comp(); //返回用于比较键的比较函数
- map.value_comp(); //返回用于比较实值的比较函数

8. 按顺序访问

- map.lower_bound(key); //返回第一个>=key的元素的迭代器
- map.upper_bound(key); //返回第一个>key的元素的迭代器

9. 容器操作

- map1.swap(map2); //交换两个map容器的元素
- map.merge(map2); //合并map2到map1中

10. 其他方法

- map.max_size(); //返回map最大可以容纳的元素个数
- map.at(key); //返回key对应的mapped值,如果key不存在,
- 抛出out_of_range

以上基本涵盖了map的常见用法,可以通过这些方法进行map的各种插入、
删除、查找、排序等多种操作。
这里再补充一些C++ map的高级用法:

11. 自定义比较函数

map<int, string, MyCompare> mapObj; 

可以通过重载小于号运算符实现自定义比较函数MyCompare,
来自定义map的排序规则。

12. 使用lambda表达式

map.insert(make_pair(key, [](int x){return x+1;});

利用lambda表达式为map的值设置函数。

13. 排序

- sort(map.begin(), map.end(), cmp); 

通过sort和自定义比较函数cmp可以对map进行排序。

14. 绑定映射

- bind(&ClassA::func, this, placeholders::_1, 
- placeholders::_2)

通过bind可以将map的值与类成员函数或全局函数绑定。

15. 区间插入

- map.insert(another_map.begin(), another_map.end());

通过区间插入可以一次性将another_map中的所有元素插入到map。

16. 编译时初始化

map<int, string> map = {{1, "a"}, {2, "b"}};

支持编译时初始化语法。

这些就是C++ map的一些高级用法,可以使map的使用更加灵活高效。
掌握后可以应对更复杂的业务场景。
好的,来举一些C++ map常用方法对应的示例代码:

1. 插入元素

```cpp
map<int, string> m; 
m[1] = "a"; 
m.insert(pair<int, string>(2, "b"));
m.insert(make_pair(3, "c"));
```

2. 删除元素 

```cpp
m.erase(1); // 删除键为1的元素
auto it = m.find(2); 
m.erase(it); // 根据迭代器删除元素
```

3. 查找元素

```cpp 
string value = m[3]; // 找到键3对应的值
if(m.count(2) > 0){
  // 键2存在
}
```

4. 遍历元素

```cpp
for(auto& p : m){
  // p是pair
}

for(auto it=m.begin(); it!=m.end(); ++it){
  // 遍历所有元素  
}
```

以上代码展示了一些map常用方法的示例,涵盖插入、删除、查找、遍历
等操作。这些方法结合起来可以完成复杂的map操作。
是的,C++中map容器也有类似Python字典的get方法。

主要有两种实现方式:

1. 利用C++17新引入的try_emplace方法:

```cpp
map<int, string> m;

auto result = m.try_emplace(1, "a"); 

string value = result.first->second; // 获取map[1]的值
```

如果key存在,try_emplace不会插入新元素,直接返回已存在元素的迭代器。

2. 自己封装一个get方法:

```cpp
template <typename K, typename V>
V get(map<K,V>& m, const K& key, const V& defaultValue) {

  auto it = m.find(key);
  if (it != m.end()) {
    return it->second;
  }
  return defaultValue;
}

string s = get(m, 1, "N/A"); 
```

这个get方法和Python的dict.get功能类似,如果key不存在,返回默认值。

所以C++中虽然map容器没有直接内置get方法,
但我们可以通过一些小技巧实现类似的功能。