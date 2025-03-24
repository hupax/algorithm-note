//
// Created by 沙枭 on 2024/3/26.
//
#include "iostream"

using namespace std;

int main()
{
    int sco = 0;
    while (cin >> sco)
    {
        if (sco < 0 || sco > 100)
        {
            cout << "Score is error!" << endl;
        } else if (sco <= 59)
        {
            cout << 'E' << endl;
        } else if (sco <= 69)
        {
            cout << 'D' << endl;
        } else if (sco <= 79)
        {
            cout << 'C' << endl;
        } else if (sco <= 89)
        {
            cout << 'B' << endl;
        } else
        {
            cout << 'A' << endl;
        }
    }
}
/*输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
90~100为A;
80~89为B;
70~79为C;
60~69为D;
0~59为E;对于每组输入数据，输出一行。
 如果输入数据不在0~100范围内，请输出一行：“Score is error!”。*/