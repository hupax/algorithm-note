//
// Created by supanx on 25-2-19.
//
//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define INF 65535
#define MAX(x, y) ((x) > (y) ? (x) : (y))


typedef struct Books {
  int a;
} Book;

const int link = 1, m = 8;
//m = 0;
//#define ll long long
typedef long long ll;

int main() {
    ll a;
    a = 110;
    const ll b = 123;
//    b = 11;
//    cout << typeof(a) << endl;
    if (a & 1) cout << 1 << endl;
    else cout << 0 << endl;
    printf("%lld\n", a);
    printf("%d\n", INF);
    printf("%p\n", 18);
    printf("%d\n", MAX(11, 12));
    
    int c = 18;
    int e = c << 1;
    cout << e << endl;
    c = (c << 2) + (c << 1) + c;
    cout << c << endl;
    
    int d[6] = {8, 2, 3, 4, 5, 6};
    int t[3][3];
    t[0][0] = 5, t[0][1] = 3;
    int (*u)[3] = t;
    int (*y)[3][3] = &t;

    int *z = *u;
    cout << "*z" << *z << endl;
    
    int (*p)[6];
    p = &d;
//    int *q = *d;
//    p++;
//    cout << p << d << *p << *d << endl;
    printf("%p %p %d %d\n", p + 1, d, *(p + 1), *(d + 1));
    
    
    return 0;
}
