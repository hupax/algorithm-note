//
// Created by 沙枭 on 2024/3/25.
//
#include "iostream"
#include "string"

using namespace std;

int main()
{
    char ch;
    int n = 364;
    int num = 0;
    bool result = false;
    string str;
//    注意最后一个参数是字符，用单引号，第二个参数是string型
    cout << "ch: " << "the num: " << "str: ," << endl;
    cin >> ch >> num;
    getline(cin,str,',');
    cout << "ch: " << ch << " the num: " << num << " str: " << str << endl;

    if (num > n)
    {
        cout << result << endl;
    }
    else if (num == n)
    {
        result = true;
        cout << result << endl;
    } else
    {
        cout << "smaller" << result << endl;
//        使用return 可以方便地结束程序,次句的下面不会再执行,但似乎finally返回09
        return 0;
    }
    string level = "非 > 比较操作 > 逻辑与 > 逻辑或";
    cout << "here" << endl;
    cout << level << endl;

}