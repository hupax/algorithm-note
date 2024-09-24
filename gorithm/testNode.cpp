//
// Created by 沙枭 on 2024/4/14.
//
#include "vector"
#include <iostream>
#include <sstream>
#include <string>
#include "cstddef"
#include "cstdlib"
#include "cmath"
#include "iomanip"
#include "map"
#include "algorithm"
#include "numeric"
#include "bits/stdc++.h"
#include <iostream>
#include "string"

#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

// 自定义比较函数
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second; // 根据值排序
    }
    return a.first < b.first; // 如果值相同，根据键排序
}

int main() {
    std::map<int, int> m = {{1, 20}, {3, 10}, {2, 20}, {5, 10}};
    std::vector<std::pair<int, int>> v(m.begin(), m.end());

    std::sort(v.begin(), v.end(), compare);

    for (const auto& pair : v) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    string line = "HJK";
    if (isupper(line[1]))

    return 0;
}