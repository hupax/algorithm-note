//
// Created by 沙枭 on 2024/4/10.
//
// 判断回文字符串
#include "stack"
#include "iostream"

using namespace std;

bool isPalindrome(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (isalnum(c))
            st.push(tolower(c));
    }
    for (char c : s)
    {
        if (isalnum(c))
            if (tolower(c) != st.top())
                return false;
        st.pop();
    }
    return true;
}