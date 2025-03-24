//
// Created by 沙枭 on 2024/4/1.
//
// draw
/*
#include "iostream"
#include "string"

using namespace std;

int main()
{
    int w, h;
    while (cin >> w >> h && (w & h))
    {
        string sw = "+";
        string sh = "|";
        for (int i = 0; i < w; ++i) {
            sw += "-";
            sh += " ";
        }
        sw += "+";
        sh += "|";
        cout << sw << endl;
        for (int i = 0; i < h; ++i) {
            cout << sh << endl;
        }
        cout << sw << endl;
//        cout << endl;
    }
}*/
#include <iostream>
using namespace std;
int main() {
	int n, m;
	int i, j;
	while (cin >> n >> m) {
		cout << "+";
		for (i = 0; i < n; i++) cout << "-";
		cout << "+" << endl;
		for (j = 0; j < m; j++) {
			cout << "|";
			for (i = 0; i < n; i++) cout << " ";
			cout << "|" << endl;
		}
		cout << "+";
		for (i = 0; i < n; i++) cout << "-";
		cout << "+" << endl;
		cout << endl;
	}
	return 0;
}

