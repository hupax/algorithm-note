好的！我们来一步步学习如何在C++中使用**Lambda表达式**
，并通过它们来实现自定义比较函数以及其他常见用法。我会尽量用简单、易懂的语言来解释，确保你能理解。

### 什么是 Lambda 表达式？

**Lambda 表达式**是一种**匿名函数**
，你可以在代码中直接定义它，而不需要像普通函数那样在其他地方单独定义。

Lambda 表达式通常用于一些简单的场景，比如自定义排序、遍历容器等，尤其是在你只需要定义一次而不打算多次复用的时候。

### 1. **Lambda 表达式的基本语法**

```cpp
[捕获列表] (参数列表) -> 返回类型 { 函数体 }
```

- **捕获列表**：用来捕获外部的变量，可以让 Lambda 内部使用外部的变量。
- **参数列表**：Lambda 的输入参数，和普通函数的参数类似。
- **返回类型**：可以省略，如果不写返回类型，编译器会自动推导。
- **函数体**：Lambda 的具体操作内容。

#### 一个最简单的 Lambda 表达式例子：

```cpp
#include <iostream>

int main() {
    auto sayHello = []() { std::cout << "Hello, world!" << std::endl; };
    sayHello();  // 调用 Lambda 表达式
    return 0;
}
```

- **auto**：这里 `sayHello` 是一个 Lambda 表达式，`auto`
  会自动推导类型。
- `[]`: 空的捕获列表，表示 Lambda 内部没有使用外部的变量。
- `()`：参数列表为空，表示这个 Lambda 不接受任何参数。
- `{ std::cout << "Hello, world!" << std::endl; }`：这是
  Lambda 的函数体，表示执行这段代码。

### 2. **Lambda 表达式作为自定义比较函数**

在排序中，我们常常需要自定义比较函数，而 Lambda
表达式非常适合这种场景。它可以直接写在排序调用的位置，使得代码更简洁。

#### 示例：使用 Lambda 表达式对数组进行排序

假设我们有一个整数数组，想要按降序排序。

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // 使用 Lambda 表达式作为自定义比较函数
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;  // 降序比较，如果 a > b 则 a 应该排在 b 前面
    });

    // 输出排序结果
    for (int link : numbers) {
        std::cout << link << " ";
    }

    return 0;
}
```

#### 输出结果：

```
9 6 5 5 2 1
```

-
`std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });`：
    - 这里使用了 `std::sort` 函数的第三个参数，用 Lambda
      表达式定义了一个比较规则。
    - `[](int a, int b)` 是 Lambda 表达式，它接受两个整数 `a`
      和 `b`，然后比较 `a > b` 来决定顺序，达到降序排序的效果。

### 3. **捕获外部变量**

Lambda 表达式的捕获列表用于捕获外部的变量，使得你可以在
Lambda 内部访问外部的变量。

#### 示例：捕获外部变量进行排序

我们想对数组中的数字进行排序，但是这次排序的规则取决于外部的一个变量。

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
    bool ascending = false;  // 决定是升序还是降序

    // 使用 Lambda 表达式捕获外部变量 ascending
    std::sort(numbers.begin(), numbers.end(), [ascending](int a, int b) {
        if (ascending) {
            return a < b;  // 升序
        } else {
            return a > b;  // 降序
        }
    });

    // 输出排序结果
    for (int link : numbers) {
        std::cout << link << " ";
    }

    return 0;
}
```

#### 输出结果：

```
9 6 5 5 2 1  （因为 ascending 是 false，所以按降序排序）
```

- `ascending` 是一个外部的布尔变量，用来决定排序的方向。
- `[ascending]` 捕获了外部的变量 `ascending`，使得 Lambda
  表达式可以根据这个变量决定排序规则。

### 4. **按引用捕获外部变量**

默认情况下，Lambda 捕获外部变量是**按值捕获**的，也就是说
Lambda 内部的变量是外部变量的**拷贝**。如果你希望 Lambda
能够修改外部变量，需要使用**按引用捕获**。

#### 示例：使用按引用捕获修改外部变量

```cpp
#include <iostream>

int main() {
    int count = 0;

    // 使用按引用捕获 [&]，这样 Lambda 就可以修改外部变量 count
    auto increment = [&]() {
        count++;
    };

    increment();  // 调用 Lambda，count 变为 1
    increment();  // 调用 Lambda，count 变为 2

    std::cout << "Count: " << count << std::endl;

    return 0;
}
```

#### 输出结果：

```
Count: 2
```

- `[&]` 表示按引用捕获所有外部变量，这意味着 `count` 在
  Lambda 内部被修改后，外部的 `count` 也会被改变。

### 5. **Lambda 表达式的其他常见用法**

#### 示例 1：使用 Lambda 遍历容器

你可以使用 Lambda 和 `for_each` 遍历容器中的元素，并对它们进行操作。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 Lambda 遍历并输出每个元素
    std::for_each(numbers.begin(), numbers.end(), [](int link) {
        std::cout << link << " ";
    });

    return 0;
}
```

#### 输出结果：

```
1 2 3 4 5
```

#### 示例 2：使用 Lambda 过滤容器中的元素

使用 `std::remove_if` 和 Lambda 可以轻松实现条件删除，比如删除所有大于
3 的元素。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 Lambda 表达式删除大于 3 的元素
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int link) {
        return link > 3;
    }), numbers.end());

    // 输出结果
    for (int link : numbers) {
        std::cout << link << " ";
    }

    return 0;
}
```

#### 输出结果：

```
1 2 3
```

### 6. **Lambda 表达式与返回值**

Lambda 表达式可以像普通函数一样有返回值。如果 Lambda
表达式的返回类型是可以推导的，你可以省略返回类型。如果无法推导，或者你想明确指定返回类型，可以使用
`->` 来指定。

#### 示例：指定返回类型

```cpp
#include <iostream>

int main() {
    // 返回两个整数相加的 Lambda，并且显式指定返回类型为 int
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    int result = add(3, 4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

#### 输出结果：

```
Result: 7
```

### 总结

Lambda 表达式是 C++ 中一个强大而灵活的工具，特别适合编写简洁、高效的代码。在竞赛中，Lambda
表达式可以用来定义简短的匿名函数，常见的用法包括：

- 自定义排序
- 捕获外部变量
- 遍历和过滤容器

通过掌握 Lambda
表达式，你可以更轻松地在代码中实现临时的功能而不需要定义额外的函数，使得代码更加简洁明了。如果你对某部分仍有疑问，随时问我！