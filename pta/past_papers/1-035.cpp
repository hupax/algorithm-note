//
// Created by 沙枭 on 2024/4/6.
//
// L1-035 情人节
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    vector<string> vector1;
    while (1)
    {
        string line;
        cin >> line;
        if (line == ".") break;
        vector1.push_back(line);
    }
    int len = vector1.size();
    if (len >= 14)
        cout << vector1[1] << " and " << vector1[13] <<
                " are inviting you to dinner..." << endl;
    else if (len >= 2)
        cout << vector1[1] << " is the only one for you..." << endl;
    else cout << "Momo... No one is for you ..." << endl;
}