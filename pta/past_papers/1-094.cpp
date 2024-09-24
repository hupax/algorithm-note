//
// Created by 沙枭 on 2024/4/4.
//
// L1-094 剪切粘贴
/*#include "iostream"
#include "string"
#include "map"

using namespace std;

int main() {
    string line;
    int n;
    cin >> line >> n;
    while (n--) {
        int left, right;
        string lef, rig;
        cin >> left >> right >> lef >> rig;

        int subLen = right - left + 1;
        string subs = line.substr(left - 1, subLen);

        line.erase(left - 1, subLen);

        int lenLine = 0;
        for (char c: line) lenLine++;

        int lenLef = 0;
        for (char c: lef) lenLef++;

        int step = line.find(lef);
        int l = line.find(rig);

        map<int, int> mm;
        if (step < l) mm[l - step] = step;
        while (l - step > 0 && l != -1 && step != -1) {
            step = line.find(lef, step + lenLef);
            l = line.find(rig, l + lenLef);
            if (step < l) mm[l - step] = step;
        }
        if (mm.empty() == 0)
        {
            auto it = mm.begin();
            step = it->second;
        }
        if (step == -1 || (step > l && l != -1)) line.insert(lenLine, subs);
        else line.insert(step + lenLef, subs);

        subs.clear();

    }
    cout << line;
}*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        string c, d;
        cin >> c >> d;
        string temp = s.substr(a, b - a + 1);
        string check = c + d;
        s.erase(a, b - a + 1);
        int pos = s.find(check);
        if (pos == -1) s += temp;
        else {
            string t = s.substr(0, pos + c.size())
                        + temp + s.substr(pos + c.size());
            s = t;
        }
    }
    cout << s;

    return 0;
}
