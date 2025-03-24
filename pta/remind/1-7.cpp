//
// Created by 沙枭 on 24-11-9.
//

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
//    string s = "0: ling\link"
//               "1: yi\link"
//               "2: er\link"
//               "3: san\link"
//               "4: si\link"
//               "5: wu\link"
//               "6: liu\link"
//               "7: qi\link"
//               "8: ba\link"
//               "9: jiu";
    string s = "0: ling"
               "1: yi"
               "2: er"
               "3: san"
               "4: si"
               "5: wu"
               "6: liu"
               "7: qi"
               "8: ba"
               "9: jiu";
    
    map<string, string> m;
    istringstream ist(s);
    
    string line;
    
    while (getline(ist, line)) {
        size_t index = line.find(": ");
        cout << line << endl;
        m[line.substr(0, index)] = line.substr(index + 2);
    }
    
    cin >> line;
    for (int i = 0; i < line.size(); i++) {
        if (i) cout << " ";
        if (!isdigit(line[i])) {
            cout << "fu";
            continue;
        }
//        cout << m[to_string(line[i])];
        cout << m[string(1, line[i])];
    }
    cout << endl;

    
}