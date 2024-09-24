//
// Created by 沙枭 on 2024/4/6.
//
// L1-044 稳赢
#include "iostream"
#include "map"
#include "string"

using namespace std;

int main()
{
    map<string, string> map1;
    map1["ChuiZi"] = "Bu";
    map1["JianDao"] = "ChuiZi";
    map1["Bu"] = "JianDao";
    int n;
    string line;
    cin >> n;
    int flag = 0;
    while (cin >> line && line != "End")
    {
        if(flag == n)
        {
            cout << line << endl;
            flag = 0;
        }
        else
        {
            cout << map1[line] << endl;
            flag++;
        }
    }
}