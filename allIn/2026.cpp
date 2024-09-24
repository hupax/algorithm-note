//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
#include "string"

using namespace std;

int main()
{
    string lien;
    while (cin >> lien && lien.empty() == 0 && lien.length() <= 100)
    {
        for (int i = 0; i < lien.length(); ++i) {
            if (i == 0)
            {
                cout << (char) toupper(lien[i]);
                continue;
            }
            cout << lien[i];
        }
        cout << ' ';
    }
    cout << endl;
    return 0;
}