//
// Created by 沙枭 on 2024/4/3.
//
#include "iostream"
#include "string"
#include "iomanip"

using namespace std;

void sandglass(int l, char c, int swu);

int main()
{
    int n;
    char c;
    while (cin >> n >> c && n > 0)
    {
        int g = 1;
        int ff = 1;
        while (g <= n)
        {
            ff += 2;
            g += 2 * ff;
        }
        g -= 2 * ff;
        ff -= 2;
        sandglass(ff, c, ff);
        cout << n - g << endl;
    }
}
void sandglass(int l, char c, int swu)
{
    string s;
    s = "";
    for (int i = 0; i < l; ++i) {
        s += c;
    }
    if (s.empty() == 0) cout << setw(swu--) << s << endl;
    if (l > 0) sandglass(l - 2, c, swu);
    if (l > 1) cout << setw(swu + 1) << s << endl;
}
