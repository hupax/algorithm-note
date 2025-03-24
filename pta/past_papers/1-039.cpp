//
// Created by 沙枭 on 2024/4/6.
//
// L1-039 古风排版
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

int main() {
    int n;
    string line;

    // 读取输入
    cin >> n;
    cin.ignore();
    getline(cin, line);

    // 将输入字符串转换为二维 vector
    vector<vector<char>> matrix(n);
    for (int i = 0; i < line.size(); i += n) {
        for (int j = 0; j < n; j++) {
            if (i + j < line.size()) {
                matrix[j].push_back(line[i + j]);
            } else {
                matrix[j].push_back(' ');
            }
        }
    }

    // 反转每一列
    for (auto& col : matrix) {
        reverse(col.begin(), col.end());
    }

    // 输出结果
    for (const auto& col : matrix) {
        for (char c : col) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
/*#include <iostream>
#include <vector>
#include <string>

int main() {
    int N;
    std::string str;

    // 读取输入
    std::cin >> N;
    std::getline(std::cin, str);

    // 将字符串转换为二维vector
    std::vector<std::vector<char>> matrix(N);
    int j = N - 1;
    for (char c : str) {
        matrix[j].push_back(c);
        j--;
        if (j < 0) {
            j = N - 1;
        }
    }

    // 输出排版后的结果
    for (int i = 0; i < N; i++) {
        for (char c : matrix[i]) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}*/