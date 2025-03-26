#include <iostream>
using namespace std;


int main() {
    int a[]={1, 2,3};
    int *b=&a[0];
    b++;
    cout << a[0] << " ";
    cout << *b;
}
