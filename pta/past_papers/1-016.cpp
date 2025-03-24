//
// Created by 沙枭 on 2024/4/5.
//
// L1-016 查验身份证
/*Z：0 1 2 3 4 5 6 7 8 9 10
  M：1 0 X 9 8 7 6 5 4 3 2*/
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool all = true;
    while (n--)
    {
        string line;
        cin >> line;

        vector<int> vector1;
        bool flag = false;
        for (int i = 0; i < line.length() - 1; ++i) {
            if (isdigit(line[i]))
            {
                int t = (int) (line[i] - '0');
                vector1.push_back(t);
            } else
            {
                flag = true;
                all = false;
                break;
            }
        }
        if (flag) cout << line << endl;
        else
        {
            char lineLast = line[17];
            int quanZ[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6,
                             3, 7, 9, 10, 5, 8, 4, 2};
            char M[11] = {'1', '0', 'X', '9', '8',
                          '7', '6', '5', '4', '3', '2'};
            int sum = 0;
            for (int i = 0; i < vector1.size(); ++i) {
                sum += vector1[i] * quanZ[i];
            }
            char last = M[sum % 11];
            bool checker = lineLast == last;
            if (checker) continue;
            else
            {
                cout << line << endl;
                all = false;
            }
        }
    }
    if (all) cout << "All passed" << endl;
}