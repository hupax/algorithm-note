//
// Created by 沙枭 on 2024/4/14.
//
// L2-002 链表去重
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;

struct edge
{
    int address;
    int data;
    int next;
};

void insert(edge *list, int address, int data, int next)
{
    list[address].address = address;
    list[address].data = data;
    list[address].next = next;
}

void printNode(edge *list, int head)
{
    while (head != -1)
    {
        cout << setw(5) << setfill('0') << list[head].address << " ";
        cout << list[head].data << " ";
        if (list[head].next == -1) cout << -1 << endl;
        else
            cout << setw(5) << setfill('0') << list[head].next << " " << endl;
        head = list[head].next;
    }
}

int main()
{
    int fAddress, N;
    cin >> fAddress >> N;
    edge *list = new edge[100000];
    int address, data, next;
    for (int i = 0; i < N; ++i) {
        cin >> address >> data >> next;
        insert(list, address, data, next);
    }
    unordered_map<int, int> umii;
    int current = fAddress;
    int duHead = -1, duTail = -1, uniHead = -1, uniTail = -1;

    while (current != -1)
    {
        int absData = abs(list[current].data);
        if (umii.count(absData) == 0)
        {
            umii[absData] = current;
            if (uniHead == -1) uniHead = current;
            else
                list[uniTail].next = current;
            uniTail = current;
        } else
        {
            if (duHead == -1) duHead = current;
            else
                list[duTail].next = current;
            duTail = current;
        }
        current = list[current].next;
    }
    if (duTail != -1) list[duTail].next = -1;
    if (uniTail != -1) list[uniTail].next = -1;

    printNode(list, uniHead);
    printNode(list, duHead);

    delete[] list;
    return 0;
}
/*00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
 00000 -15 99999
00100 21 23854*/
/*
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1*/