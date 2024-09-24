C++中可以使用`setw()`和`setfill()`等函数来对输出进行格式化。下面是一些常见的格式化输出的方法:

1. **居中输出**:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(20) << setfill(' ') << "Centered Text" << endl;
    return 0;
}
```
输出结果:
```
                Centered Text
```
`setw(20)`设置输出宽度为20个字符,`setfill(' ')`设置填充字符为空格,这样就可以实现居中显示。

2. **左对齐输出**:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(20) << "Left Aligned" << endl;
    return 0;
}
```
输出结果:
```
Left Aligned
```
使用`left`操纵符可以实现左对齐输出。

3. **右对齐输出**:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << right << setw(20) << "Right Aligned" << endl;
    return 0;
}
```
输出结果:
```
           Right Aligned
```
使用`right`操纵符可以实现右对齐输出。

4. **设置小数点位数**:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159;
    cout << fixed << setprecision(2) << pi << endl;
    return 0;
}
```
输出结果:
```
3.14
```
使用`fixed`和`setprecision(2)`可以设置小数点后保留2位小数。

这些是C++中常见的格式化输出的方法,可以根据实际需求进行灵活使用。
好的,继续介绍C++中更多的格式化输出方法:

5. **金钱格式化**:
```cpp
#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

int main() {
    locale::global(locale(""));
    double amount = 1234.56;
    cout << fixed << setprecision(2) << setw(12) << setfill('$') << amount << endl;
    return 0;
}
```
输出结果:
```
   $1,234.56
```
使用`setw(12)`设置输出宽度为12个字符,`setfill('$')`设置填充字符为美元符号,`fixed`和`setprecision(2)`设置小数点保留2位小数,可以实现金钱格式化输出。

6. **日期格式化**:
```cpp
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    time_t t = time(NULL);
    struct tm* local = localtime(&t);
    cout << setw(2) << setfill('0') << local->tm_mday << "/"
         << setw(2) << setfill('0') << local->tm_mon + 1 << "/"
         << local->tm_year + 1900 << endl;
    return 0;
}
```
输出结果:
```
03/04/2024
```
使用`localtime()`获取当前时间,然后使用`setw(2)`和`setfill('0')`来格式化日期输出。

7. **十六进制输出**:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num = 0xFF;
    cout << hex << showbase << num << endl;
    return 0;
}
```
输出结果:
```
0xFF
```
使用`hex`操纵符可以将数字以十六进制格式输出,`showbase`可以显示十六进制前缀`0x`。

以上就是C++中常见的一些格式化输出的方法,可以根据需要灵活使用。