//
// Created by 沙枭 on 24-5-20.
//
// 7-37 模拟EXCEL排序
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<string, pair<string, string>> students;
    int n, c;
    cin >> n >> c;
    string id, name, score;
    for (int i = 0; i < n; ++i) {
        cin >> id >> name >> score;
        students[id] = {name, score};
    }
    vector<pair<string, pair<string, string>>> ans(students.begin(), students.end());
    if (c == 2) {
        sort(ans.begin(), ans.end(), [](pair<string, pair<string, string>> &a,
            pair<string,pair<string,string>> &b)
        {
          return a.second.first == b.second.first ? a.first < b.first : a.second.first
              < b.second.first;
        });
    }
    else if (c == 3) {
        sort(ans.begin(), ans.end(), [](pair<string, pair<string, string>> &a,
            pair<string,pair<string,string>> &b)
        {
          return a.second.second == b.second.second ? a.first < b.first :
                 a.second.second < b.second.second;
        });
    }
    for (auto &[k, v] : ans) {
        cout << k << " " << v.first << " " << v.second << endl;
    }
}
/*
在N行中输出按要求排序后的结果，即：
 当C=1时，按学号递增排序；
 当C=2时，按姓名的非递减字典序排序；
 当C=3时，按成绩的非递减排序。
 当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。
输入样例:
3 3
000007 James 85
000010 Amy 90
000001 Zoe 60

输出样例:
000001 Zoe 60
000007 James 85
000010 Amy 90
 */