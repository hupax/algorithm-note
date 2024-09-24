//
// Created by 沙枭 on 2024/4/9.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> schools(n);
        for (int &i : schools) {
            cin >> i;
        }
        int step = n / 10;
        int mod = n % 10;

        for (int school = 1; school <= n; school++) {
            if (school == 1) {
                // 第一所学校的第一队可以直接入座
                for (int i = 0; i < schools[0]; i++) {
                    cout << (i == 0 ? "#" : " ") << schools[0] * 10 + i + 1 << endl;
                }
            } else if (school <= step) {
                // 前几所学校可以直接入座
                for (int i = 0; i < schools[school - 1]; i++) {
                    cout << (i == 0 ? "#" : " ") << (school - 1) * 10 + i + 1 << endl;
                }
            } else {
                // 后面的学校需要隔位就坐
                int start = (school - 1) * 10;
                for (int i = 0; i < schools[school - 1]; i++) {
                    cout << (i == 0 ? "#" : " ") << start + (i % 2) + 1 << endl;
                }
            }

            // 跳过没有队伍的学校
            if (school <= step) continue;
            if (mod > 0) {
                // 如果剩余的学校数不能组成一个完整的小组，则继续隔位就坐
                mod--;
            } else {
                // 如果剩余的学校数足够组成一个完整的小组，则直接入座
                mod = 10;
            }
            schools[school - 1]--;
            if (schools[school - 1] == 0) {
                // 如果当前学校的队伍都已入座，跳过剩余的学校
                schools[school - 1] = 0;
                school++;
            }
        }
    }
    return 0;
}