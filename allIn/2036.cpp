//
// Created by 沙枭 on 2024/3/30.
//
// 改革春风吹满地
#include "iostream"
#include "vector"
#include "iomanip"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int m;
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> arr[i][j];
            }
        }
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == n - 1)
            {
                area += arr[i][0] * arr[0][1] - arr[0][0] * arr[i][1];
            } else
            {
                area += arr[i][0] * arr[i + 1][1] - arr[i + 1][0] * arr[i][1];
            }
        }
        if (area < 0) area = -area;
        cout << fixed << setprecision(1);
        cout << area * 0.5 << endl;
    }
}

// area[0][0]*area[1][1] - area[1][0]*area[0][1] + area[1][0]*area[2][1] - area[2][0]*area[1][1]
/*求多边形面积有多种方法,如果已知多边形各顶点坐标,可以使用以下两种常见方法:
s += arr[i][0] * arr[i+1][1] - area[i+1][0]*area[i][1]
1. 三角剖分法

将多边形划分为若干个三角形,分别求出各个三角形的面积,然后求和即可得到多边形的面积。设多边形依次连接的顶点坐标
 为(x1,y1),(x2,y2),...,(xn,yn),则划分的三角形面积可用叉乘计算:

S△ = 1/2 * |(x2-x1)(y3-y1) - (x3-x1)(y2-y1)

将所有三角形面积求和,即为多边形面积。

2. 射线法(格林公式)

在坐标平面上,构造一条从多边形外一点出发的射线,交多边形边界的奇数次(1,3,5...),则该点在多边形内;
 交偶数次(0,2,4...),则在多边形外。据此可求多边形面积:
        (x1,y1),(x2,y2),(x3,y3),...,(xn,yn)
S = 1/2 * |(x1y2 - x2y1) + (x2y3 - x3y2) + ... + (xny1 - x1yn)|

其中,(x1,y1),(x2,y2),...,(xn,yn)为多边形顶点坐标,按逆时针(或顺时针)顺序给出。||内为绝对值符号。

两种方法在计算机编程实现中都较为简便,射线法的公式更为简洁,但要注意顶点坐标给出的顺序(顺逆时针)。掌握这两种方法,
 就能方便地根据多边形顶点坐标求得其面积了。*/