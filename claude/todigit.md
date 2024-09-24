`std::stoi()` 和 `std::digittoint()` 是 C++
标准库中提供的两个不同的函数,用于处理字符和整数之间的转换。

1. `std::stoi()`:

   `std::stoi()`
   函数用于将字符串转换为整数。它位于 `<string>` 头文件中。

   ```cpp
   #include <iostream>
   #include <string>

   int main() {
       std::string str = "42";
       int num = std::stoi(str);
       std::cout << "The integer value is: " << num << std::endl; // Output: 42
       return 0;
   }
   ```

   `std::stoi()` 函数的原型如下:

   ```cpp
   int stoi(const std::string& str, std::size_t* pos = 0, int base = 10);
   ```

    - `str`: 要转换的字符串。
    - `pos`: 可选参数,用于存储转换停止的位置。
    - `base`: 可选参数,指定数字的进制,默认为 10 进制。

   如果转换失败,`std::stoi()` 会抛出 `std::invalid_argument`
   或 `std::out_of_range` 异常。

2. `std::digittoint()`:

   `std::digittoint()`
   函数用于将单个字符转换为对应的整数值。它位于 `<cctype>`
   头文件中。

   ```cpp
   #include <iostream>
   #include <cctype>

   int main() {
       char c = '7';
       int digit = std::digittoint(c);
       std::cout << "The integer value is: " << digit << std::endl; // Output: 7
       return 0;
   }
   ```

   `std::digittoint()` 函数的原型如下:

   ```cpp
   int digittoint(int c);
   ```

    - `c`: 要转换的字符。

   如果输入的字符不是数字字符,`std::digittoint()` 将返回 -1。

总的来说,`std::stoi()`
用于将整个字符串转换为整数,而 `std::digittoint()`
则用于将单个字符转换为整数。两者都是 C++ 标准库中常用的字符和整数之间的转换函数。