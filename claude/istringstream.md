在 C++ 中,可以使用 `std::getline()`
函数来读取一行包含不同类型的输入,并以空格分割。以下是一个示例代码:

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string word;
    std::vector<std::string> words;

    while (iss >> word) {
        words.push_back(word);
    }

    // 现在 words 向量包含了输入行中以空格分割的所有单词
    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

在这个例子中,我们使用 `std::getline()`
函数读取一行输入,并将其存储在 `line`
字符串中。然后,我们使用 `std::istringstream` 将 `line`
字符串转换为输入流,并使用 `>>`
运算符从输入流中逐个读取单词,并将它们存储在 `words` 向量中。

最后,我们遍历 `words` 向量,并打印出每个单词。

这种方法可以读取包含不同类型数据(如整数、浮点数等)
的单词,只要你能够将它们转换为所需的数据类型即可。例如:

```cpp
int i;
double d;
std::string s;
if (iss >> i >> d >> s) {
    // 成功读取了整数、浮点数和字符串
}
```

在C++中，你可以使用 `getline()`
函数获取一行包含不同类型的输入，并使用 `stringstream`
将输入按空格分割。以下是一个示例代码：

```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);  // 获取一行输入

    stringstream ss(line);  // 将输入字符串传递给stringstream

    string str;
    int num;
    char ch;

    ss >> str >> num >> ch;  // 按空格分割并读取不同类型的数据

    cout << "String: " << str << endl;
    cout << "Integer: " << num << endl;
    cout << "Character: " << ch << endl;

    return 0;
}
```

在上面的代码中：

1. 我们使用 `getline(cin, line)`
   从标准输入中读取一整行，包括空格，并将其存储在 `line` 字符串中。

2. 然后，我们创建一个 `stringstream` 对象 `ss`，并将 `line`
   传递给它。这样，我们就可以从 `stringstream` 中提取不同类型的数据。

3. 接下来，我们声明了不同类型的变量 `str`、`num` 和 `ch`
   ，分别用于存储字符串、整数和字符。

4. 我们使用 `ss >> str >> num >> ch` 从 `stringstream`
   中按空格分割并依次读取字符串、整数和字符。

5. 最后，我们将读取到的数据输出到控制台。

运行示例：

```
输入: Hello 42 A
输出:
String: Hello
Integer: 42
Character: A
```

这样，你就可以使用 `getline()` 和 `stringstream`
轻松地获取一行包含不同类型的输入，并按空格进行分割。
是的,可以使用其他字符来分割输入行。只需要稍微修改一下代码即可。

例如,如果要以逗号作为分隔符,可以这样做:

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string word;
    std::vector<std::string> words;

    while (std::getline(iss, word, ',')) { // 使用逗号作为分隔符
        words.push_back(word);
    }

    // 现在 words 向量包含了输入行中以逗号分割的所有单词
    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

在这个例子中,我们使用 `std::getline(iss, word, ',')`
来读取以逗号分隔的单词。你可以将 `','`
替换为任何其他你想要的分隔符,比如制表符 `'\t'`、管道符 `'|'`
等等。

总之,这种方法非常灵活,可以适应各种分隔符的需求。