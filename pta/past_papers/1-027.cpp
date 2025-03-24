//
// Created by 沙枭 on 2024/4/6.
//
// L1-027 出租
#include "iostream"
#include "set"
#include "vector"
#include "string"
//#include "functional"
#include "map"

using namespace std;

int main()
{
    string line;
    cin >> line;
    vector<int> vector1;

    for (char i : line) vector1.push_back((int)(i - '0'));
    set<int> set1(vector1.begin(), vector1.end());
//    或直接建降序set
//    set<int, greater<int>> set1(vector1.begin(), vector1.end());
/*
3,0,4,3,1,0,2,4,3,4,4*/

    cout << "int[] arr = new int[]{";
    map<int, int> map1;
    int index = 0;
    for (auto it = set1.rbegin(); it != set1.rend(); ++it)
    {
        map1[*it] = index;
        index++;
        if (it == set1.rbegin()) cout << *it;
        else cout << "," << *it;
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (auto i = vector1.begin(); i != vector1.end(); ++i)
    {
        if (i == vector1.begin()) cout<< map1[*i];
        else cout << "," << map1[*i];
    }
    cout << "};" << endl;
}