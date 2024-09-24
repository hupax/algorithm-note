C++中可以使用标准库中的`<ctime>`头文件来进行日期和时间的操作。下面是一些常用的方法来计算日期之间的天数差:

1. 使用`time_t`和`difftime()`函数

`time_t`是一个整数类型,代表从1970年1月1日00:00:00开始的秒数。我们可以将两个日期转换为`time_t`类型,然后使用`difftime()`函数计算它们的差值,并将结果转换为天数。

```cpp
#include <ctime>

int days_between(int year1, int month1, int day1,
                 int year2, int month2, int day2) {
    struct tm date1 = {0}, date2 = {0};
    date1.tm_year = year1 - 1900; // 年份从1900开始计算
    date1.tm_mon = month1 - 1;    // 月份从0开始
    date1.tm_mday = day1;
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    time_t t1 = mktime(&date1);
    time_t t2 = mktime(&date2);

    return static_cast<int>(difftime(t2, t1) / (60 * 60 * 24)); // 转换为天数
}
```

2. 使用`std::tm`结构体

`std::tm`是一个表示日期和时间的结构体,我们可以直接对其进行运算。

```cpp
#include <ctime>

int days_between(int year1, int month1, int day1,
                 int year2, int month2, int day2) {
    struct std::tm date1 = {0}, date2 = {0};
    date1.tm_year = year1 - 1900;
    date1.tm_mon = month1 - 1;
    date1.tm_mday = day1;
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    time_t t1 = mktime(&date1);
    time_t t2 = mktime(&date2);

    double diff = difftime(t2, t1);
    return static_cast<int>(diff / (60 * 60 * 24));
}
```

3. 使用`std::chrono`库(C++11及更高版本)

C++11引入了`<chrono>`头文件,提供了一种更简洁的方式来处理日期和时间。

```cpp
#include <chrono>
#include <ctime>

int days_between(int year1, int month1, int day1,
                 int year2, int month2, int day2) {
    std::tm date1 = {0}, date2 = {0};
    date1.tm_year = year1 - 1900;
    date1.tm_mon = month1 - 1;
    date1.tm_mday = day1;
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    std::time_t time1 = std::mktime(&date1);
    std::time_t time2 = std::mktime(&date2);

    auto diff = std::chrono::system_clock::from_time_t(time2) -
                std::chrono::system_clock::from_time_t(time1);

    return std::chrono::duration_cast<std::chrono::days>(diff).count();
}
```

这些示例代码都假设输入的年月日