//
// Created by 沙枭 on 2024/4/1.
//
// 4.特殊符号：~,!,@,#,$,%,^; 密码

#include "iostream"
#include "string"


using namespace std;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string line;
//        string gg[7] = {"~","!","@","#","$","%","^"};
        char gg[7] = {'~','!','@','#','$','%','^'};
        cin >> line;
        bool f = false;
        bool k = false;
        bool g = false;
        bool h = false;
        for (int i = 0; i < line.length(); ++i) {
            if (isupper(line[i])) f = true;
            if (islower(line[i])) k = true;
            if (isdigit(line[i])) g = true;
            for (char j : gg) {
                if (line[i] == j) h = true;
            }
        }
        int count = 0;
        if (f) count++;
        if (g) count++;
        if (h) count++;
        if (k) count++;
        int len = line.length();
        if (count >= 3 && len >= 8 && len <= 16) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}