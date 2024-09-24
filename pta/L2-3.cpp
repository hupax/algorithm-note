//
// Created by 沙枭 on 2024/5/2.
//
// L2-3 到底爱不爱我
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct edge
{
  char am;
  char lam;
  char ram;
  int data;
  int left;
  int right;
};
string m;
int g;
void wua(edge &y)
{
//    if (y.lam == 'f' || (y.ram == 'f' && y.data != 3)) return;
    if (y.data == 3)
    {
        if (y.lam == '1')
            y.am = '0';
        else y.am = '1';
    }
    else if (y.data == 1)
    {
        if (y.lam == '0' || y.ram == '0')
            y.am = '0';
        else y.am = '1';
    }
    else
    {
        if (y.lam == '1' || y.ram == '1')
            y.am = '1';
        else y.am = '0';
    }
//    cout << y.am << "a ";
//    return y.am;
}
int wuy(vector<edge> &v, int h, vector<int> &index)
{
    if (h < 0) return 0;
    wuy(v, v[h].left - 1, index);
    wuy(v, v[h].right - 1, index);
//    cout << endl << h + 1 << "h " << endl;
    index.push_back(h);
    if (v[h].left == 0)
    {
        v[h].lam = m[g++];
//        cout << v[h].lam << "l ";
    }
    if (v[h].right == 0 && v[h].data != 3)
    {
        v[h].ram = m[g++];
//        cout << v[h].ram << "r ";
    }
}

int main()
{
    int n, head, k;
    bool vis[35];
    cin >> n;
    vector<edge> vn(n);
    for (edge &v : vn)
    {
        cin >> v.data >> v.left;
        if (v.data != 3) cin >> v.right;
//        else v.right = 0;
//        v.lam = 'f';
//        v.ram = 'f';
        vis[v.left] = 1;
        vis[v.right] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            head = i - 1;
            break;
        }
    }
    cin >> k;
    while (k--)
    {
        cin >> m;
        g = 0;
        vector<int> index;
        wuy(vn, head, index);
//        for (int &i : index) cout << i << " ";
        for (int i = 0; i < n; ++i)
        {
//            cout << endl << i << "h " << endl;
            if (vn[index[i]].left == 0 && (vn[index[n]].data == 3 || vn[index[i]].right == 0))
                wua(vn[index[i]]);
            else
            {
                vn[index[i]].lam = vn[vn[index[i]].left - 1].am;
                if (vn[index[i]].data != 3)
                    vn[index[i]].ram = vn[vn[index[i]].right - 1].am;
                wua(vn[index[i]]);
            }
        }
        if (vn[head].am == '1')
            cout << "Ai" << endl;
        else cout << "BuAi" << endl;
    }
}
/*


6
2 6 3
1 0 0
3 4
2 0 0
3 0
1 5 2
5
11111
00000
11100
10011
01100

 6
2 6 4
1 0 0
3 1
2 0 0
3 0
1 5 2
5
11111
00000
11100
10011
01100

 */