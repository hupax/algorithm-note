//
// Created by 沙枭 on 24-5-19.
//
// 7-26 Windows消息队列
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
int n, level;
string cmd, message;
unordered_map<int, string> ms;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> q;
int main()
{
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "PUT") {
            cin >> message >> level;
//            ms[level] = message;
            q.emplace(level, message);
        }
        else {
//            if (ms.empty())
            if (q.empty())
                cout << "EMPTY QUEUE!" << endl;
            else {
//                cout << ms.begin()->second << endl;
//                ms.erase(ms.begin());
                cout << q.top().second << endl;
                q.pop();
            }
        }
    }
}
/*
9
PUT msg1 5
PUT msg2 4
GET
PUT msg3 2
PUT msg4 4
GET
GET
GET
GET

 
 */