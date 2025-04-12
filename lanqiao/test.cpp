#include <iostream>
#include <string>
using namespace std;

// 高精度减法：a - b
string subtract(string &a, string &b) {
    int la=a.size(), lb=b.size();
    int borrow=0;
    string res="";
    
    for (int i=0; i < la; i++) {
        int x=a[la-1-i]^48;  // 当前位a
        int y=(i < lb) ? b[lb-1-i]^48 : 0;  // 当前位b
        
        int diff=x-y-borrow;
        if (diff < 0) {
            diff+=10;
            borrow=1;
        }
        else {
            borrow=0;
        }
        res=(diff^48)+res;  // 拼接每一位的结果
    }
    
    // 去掉前导零
    int start=0;
    while (start < res.size() && res[start] == '0') start++;
    return start == res.size() ? "0" : res.substr(start);
}

// 用于去掉字符串中的前导零
void init(string &res) {
    int i=0;
    while (i < res.size() && res[i] == '0') {
        i++;
    }
    res=res.substr(i);
    if (res.empty()) res="0";  // 如果去掉前导零后为空，表示是零
}

// 高精度除法：a / b
string div(string a, string b) {
    if (a == "0") return "0";      // 被除数为0，商为0
    if (b == "0") return "ERROR";  // 除数为0，返回错误
    
    int la=a.size(), lb=b.size();
    string res="", cur="";     // 存储商和当前部分余数
    int q=0;  // 商
    
    for (int i=0; i < la; i++) {
        cur+=a[i];  // 当前部分添加新的一位
        
        q=0;  // 初始商为0
        
        // 找到当前部分能被除数除多少次
        while (cur.size() > lb || (cur.size() == lb && cur >= b)) {
            cur=subtract(cur, b);  // 用高精度减法操作
            q++;
        }
        
        // 如果商为零且结果为空，则跳过该位（避免前导零）
        if (res.empty() && q == 0) continue;
        
        // 将商转换为字符并加入结果
        res+=(q+'0');
    }
    
    init(res);  // 去除结果的前导零
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    string result=div(a, b);
    cout << result << endl;
    
    return 0;
}
