在 C++ 中，常用的输出格式化操作主要包括控制小数点精度、宽度、对齐、填充字符等。这些操作主要通过
`iomanip` 库中的操作符实现，例如 `std::setw`、`std::setfill`
等。以下是一些常见的格式化方法：

### 1. 控制宽度和填充

- `std::setw(link)`: 设置输出的宽度为 `link` 个字符。如果实际内容小于
  `link`，则在左侧补空格（默认）。
- `std::setfill(char)`: 设置填充字符。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(10) << 123 << std::endl;            // 输出宽度为10，左侧补空格
    std::cout << std::setw(10) << std::setfill('0') << 123 << std::endl; // 左侧补0
    return 0;
}
```

**输出**：

```
       123
0000000123
```

### 2. 控制对齐方式

- `std::left`：左对齐。
- `std::right`：右对齐（默认）。
- `std::internal`：符号在最左侧，数值部分右对齐。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(10) << std::left << 123 << std::endl;     // 左对齐
    std::cout << std::setw(10) << std::right << 123 << std::endl;    // 右对齐
    std::cout << std::setw(10) << std::internal << -123 << std::endl; // 符号在最左，数值右对齐
    return 0;
}
```

**输出**：

```
123       
       123
-       123
```

### 3. 控制小数点精度

- `std::setprecision(link)`：设置浮点数的小数位精度为 `link`
  位（影响小数部分）。
- `std::fixed`：使用定点表示法，固定小数位数。
- `std::scientific`：使用科学计数法表示浮点数。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159265;
    std::cout << std::setprecision(3) << pi << std::endl;           // 输出3位有效数字
    std::cout << std::fixed << std::setprecision(3) << pi << std::endl; // 保留3位小数
    std::cout << std::scientific << std::setprecision(3) << pi << std::endl; // 科学计数法表示
    return 0;
}
```

**输出**：

```
3.14
3.142
3.142e+00
```

### 4. 输出布尔值

- `std::boolalpha` 和 `std::noboolalpha`：控制布尔值输出为
  `true/false` 或 `1/0`。

```cpp
#include <iostream>

int main() {
    bool flag = true;
    std::cout << std::boolalpha << flag << std::endl;     // 输出 true
    std::cout << std::noboolalpha << flag << std::endl;   // 输出 1
    return 0;
}
```

**输出**：

```
true
1
```

### 5. 输出整数的不同进制格式

- `std::dec`：十进制（默认）。
- `std::hex`：十六进制。
- `std::oct`：八进制。
- `std::showbase`：显示进制前缀（如 `0x`）。
- `std::uppercase`：大写十六进制字母（`A-F`）。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num = 255;
    std::cout << std::dec << num << std::endl;           // 十进制输出
    std::cout << std::hex << num << std::endl;           // 十六进制输出
    std::cout << std::oct << num << std::endl;           // 八进制输出
    std::cout << std::showbase << std::hex << num << std::endl; // 十六进制带前缀
    std::cout << std::uppercase << std::hex << num << std::endl; // 大写十六进制
    return 0;
}
```

**输出**：

```
255
ff
377
0xff
FF
```

### 6. 使用占位符来对齐输出表格

使用 `std::setw`、`std::left`、`std::right` 等，可以创建对齐的表格格式输出。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(10) << "Name" 
              << std::setw(10) << "Age" 
              << std::setw(10) << "Score" << std::endl;

    std::cout << std::setw(10) << "Alice" 
              << std::setw(10) << 23 
              << std::setw(10) << 89 << std::endl;

    std::cout << std::setw(10) << "Bob" 
              << std::setw(10) << 25 
              << std::setw(10) << 95 << std::endl;

    return 0;
}
```

**输出**：

```
Name      Age       Score     
Alice     23        89        
Bob       25        95        
```

这些格式化方法可以帮助你控制输出的精度、宽度、对齐方式以及进制等。只要结合
`iomanip` 中的格式化操作符，就可以灵活地控制 C++ 输出的格式。