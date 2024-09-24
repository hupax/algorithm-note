//
// Created by 沙枭 on 2024/3/25.
//
#include "iostream"
#include "string"

using namespace std;

int main()
{
//    建议声明变量时初始化赋值
    string fName;
    string sentence = "there is a sentence";
    string lName;
    double num = 0;
    cin >> fName;

//    使用getline()读取整行数据，可以自动丢弃末尾换行符
//    getline()要传入输入源，读入字符串，终止字符三个参数
    getline(cin,lName,',');
//    逗号后的数据会驻留在输入缓存中，直到另一个输入声明来读取它q

//    fName = std::to_string(cin.get()); //不会

    cout << sentence << "\n" << "fName: " << fName << endl;
    cout << "lName: " << lName << endl;
}