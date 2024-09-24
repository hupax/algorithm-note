//
// Created by 沙枭 on 2024/3/28.
//
/*
#include "iostream"
#include "string.md"

using namespace std;

int main()
{
    string.md line;
    int n;
    while (cin >> n >> line && line.length() <= 50)
    {
        auto * ll = new string.md [n];
        for (int i = 0; i < n; ++i) {
            cin >> ll[i];
        }
        for (int i = 0; i < n; ++i) {
            if (ll[i][0] >= '0' && ll[i][0] <= '9')
            {
                cout << "no" << endl;
                continue;
            } else
            {
                bool flag = true;
                for (int j = 0; j < ll[i].length(); ++j) {
                    if (ll[i][j] >= 'A' && ll[i][j] <= 'Z' ||
                            ll[i][j] >= 'a' && ll[i][j] <= 'z' ||
                                ll[i][j] == '_' && ll[i][j] != ' ' ||
                                    ll[i][0] >= '0' && ll[i][0] <= '9')
                    {
                        continue;
                    } else
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    cout << "yes" << endl;
                } else
                {
                    cout << "no" << endl;
                }
            }
        }

        delete[] ll;
    }
}
*/
#include "iostream"
#include "cstring"

using namespace std;

char s[51];

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        cout << t << endl;
        cin.getline(s, 51);
        cout << t << endl;
        if (isdigit(s[0])) {
            cout << "no" << endl;
            continue;
        }
        int len = strlen(s);
        bool flag = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] != '_' && isdigit(s[i]) == 0 && isalpha(s[i]) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}























