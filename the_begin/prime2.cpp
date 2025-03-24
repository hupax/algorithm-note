//
// Created by 沙枭 on 2024/4/6.
//
#include "iostream"
#include "string"

using namespace std;

bool prime(string s)
{
    if (s.size() == 1 && stoi(s) == 1 || stoi(s) == 2 || stoi(s) == 3)
        return 1;
    else
    {
        int sum = 0;
        for (char c : s) sum += (int)(c - '0');
        if ((int)(s[s.size() - 1] - '0') % 2 != 0 && sum % 3 != 0)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string line;
        cin >> line;
        if (prime(line)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}