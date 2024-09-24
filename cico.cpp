//
// Created by 沙枭 on 2024/3/25.
//
#include <iostream>
using namespace std;
// 能方便掉用头文件例程的缩写
int main()
{
    float num = 0;
//    num = 2343;
    cout << "Please enter a number: " << endl;
    cin >> num;
    cout << "The what I entered: " << endl << num << endl;
    cin.ignore();
//    C out, C in,  输入输出
//
/*
 cin.get() 是一个函数，它从输入流中读取一个字符，
 包括空格和换行符。如果输入流中没有字符，它将等待用户输入
 char c;
 c = cin.get();
 cin.ignore() 是一个函数，它从输入流中丢弃一个或多个字符。它通常用于清除缓冲区中的无用字符。
 你可以指定要忽略的字符数，以及在遇到哪个字符时停止忽略。
 如果不提供任何参数，它将默认丢弃一个字符，或者直到遇到换行符。
 cin.ignore(100, '\n');
 这行代码将忽略最多 100 个字符，或者直到遇到换行符为止。*/
}