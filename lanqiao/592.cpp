//
// Created by 沙枭 on 24-9-29.
//
#include <bits/stdc++.h>

#include <iostream>

// 函数计算从 1 到 n 中“2”出现的次数
int countDigitTwo(int n)
{
    int count = 0;
    int factor = 1;  // factor 是位数（1：个位，10：十位，100：百位……）
    
    while (n / factor > 0)
    {
        // 逐位提取当前位的高位、当前位和低位
        int lower = n - (n / factor) * factor;        // 低位
        int current = (n / factor) % 10;              // 当前位
        int higher = n / (factor * 10);               // 高位
        
        // 计算当前位上“2”出现的次数
        if (current < 2)
        {
            count += higher * factor;  // 当前位小于2的情况
        }
        else if (current == 2)
        {
            count += higher * factor + lower + 1;  // 当前位等于2的情况
        }
        else
        {
            count += (higher + 1) * factor;  // 当前位大于2的情况
        }
        
        factor *= 10;  // 处理下一个更高的位
    }
    
    return count;
}

int main()
{
    int n = 2020;
    std::cout << "The number of 2s from 1 to " << n << " is: " << countDigitTwo(n) << std::endl;
    return 0;
}
