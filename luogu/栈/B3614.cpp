//
// Created by supanx on 25-3-5.
//
#include <iostream>
#include <string>
using namespace std;
const int maxs = 1e8;
int n, m, k, size_s = 0, sstack[maxs];
string op;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while (n--) {
        cin >> m;
        
        while (m--) {
            cin >> op;
            if (op[2] == 's') {
                cin >> k;
                sstack[size_s++] = k;
            }
            if (op[2] == 'p') size_s ? size_s-- : cout << "Empty";
            if (op[2] == 'e') size_s ?  cout << sstack[size_s] : cout << "Anguei!";
            
            cout << endl;
        }
    }
    
    return 0;
}