//
// Created by 沙枭 on 2024/4/5.
//
// L1-020 帅到没朋友
#include "iostream"
#include "string"
#include "vector"
#include "set"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> vector1;
    vector<string> vector2;
    while (n--)
    {
        int k;
        cin >> k;
        while (k--)
        {
            string line;
            cin >> line;
            vector1.push_back(line);
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        string line1;
        cin >> line1;
        vector2.push_back(line1);
    }
//    去重
    set<string> set1(vector1.begin(), vector1.end());
    vector1.assign(set1.begin(), set1.end());
    set<string> set2(vector2.begin(), vector2.end());
    vector2.assign(set2.begin(), set2.end());

    bool kongGe = true;
    for (auto &i : vector2)
    {
        bool flag = true;
        for (auto &t : vector1)
        {
            if (i == t) flag = false;
        }
        if (flag)
        {
            if (kongGe)
            {
                cout << i;
                kongGe = false;
            } else cout << " " << i;
        }
    }
    if (kongGe) cout << "No one is handsome";
    cout << endl;
    return 0;
}
/*        auto ** arr = new int*[link];
        auto * lenArr = new int[link];
        for (int i = 0; i < link; ++i) {
            int len;
            cin >> len;
            lenArr[i] = len;
            arr[i] = new int [len];
            for (int j = 0; j < len; ++j) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < link; ++i) {
            for (int j = 0; j < lenArr[i]; ++j) {
                cout << arr[i][j] << " ";
            }
        }


        for (int i = 0; i < link; ++i) {
            for (int j = 0; j < lenArr[i]; ++j) {
                delete[] arr[i];
            }
        }
        delete[] arr;
        delete[] lenArr;*/