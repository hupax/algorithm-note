//
// Created by supanx on 25-2-19.
//
#include <iostream>
#include <stdlib.h>
#define maxx 105

using namespace std;

typedef struct
{
  int *data;
  int maxsize;
  int len;
} Arr;

Arr initArr()
{
    Arr b;
    b.data = (int *) malloc(sizeof(int) * maxx);
    if (b.data == NULL)
    {
        cout << "b.data = NULL" << endl;
    }
    b.maxsize = maxx;
    b.len = 0;
    return b;
}
int add(Arr *a, int k)
{
    if (a->len >= a->maxsize) return 0;
    a->data[a->len++] = k;
    return 1;
}
int insert(Arr *a, int k, int i)
{
    if (a->len >= a->maxsize) return 0;
    for (int j = a->len; j > i; j--)
    {
//		swap(a->data[j], a->data[j - 1]);
//		int t = a->data[j];
//		a->data[j] = a->data[j - 1];
//		a->data[j - 1] = t;
        a->data[j] = a->data[j - 1];
    }
    a->data[i] = k;
    a->len++;
    return 1;
}
int find(Arr *a, int k) {
    for (int i = 0; i < a->len; i++) {
        if (a->data[i] == k) return i;
    }
    return -1;
}
int del(Arr *a, int k) {
    int i = find(a, k);
    if (i == -1) return 0;
    for (int j = i; j < a->len; j++) {
        a->data[j] = a->data[j + 1];
    }
    a->len--;
    return 1;
}
int main()
{
    int o[] = {1, 2};
    cout << "Hello World" << endl;
    Arr a = initArr();
    add(&a, 5);
    add(&a, 8);
    add(&a, 3);
    insert(&a, 6, 1);
    cout << a.data[2] << endl;
    
    cout << find(&a, 1) << endl;
    cout << del(&a, 0) << endl;
    
    for (int i = 0; i < a.len; i++)
    {
        cout << i << " : " << a.data[i] << endl;
    }
    cout << "----------" << endl;
    
    
}




































