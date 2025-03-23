//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> ans;
    for (int &it : asteroids) {
        if (ans.empty() || it > 0) ans.push_back(it);
        else {
            while (!ans.empty() && ans.back() > 0 && ans.back() < -it) {
                ans.pop_back();
            }
            if (ans.empty() || ans.back() == it || (ans.back() < 0 && it < 0)) ans.push_back(it);
            else if (ans.back() == -it) ans.pop_back();
        }
    }
    return ans;
}
int main() {
    int n;
    char c;
    cin >> n;
    vector<int> a(n);
    for (int &it:a) {
//        getchar();
        cin >> c;
        cin >> it;
//        cout << it << endl;
    }
//    getchar();
//    cin >> a[0];
//    getchar();
//    cin >> a[1];
//    getchar();
//    cin >> a[2];
//    getchar();
//    cin >> a[3];
    for (int &it : asteroidCollision(a)) cout << it << " ";
    return 0;
}