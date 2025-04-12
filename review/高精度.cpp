//
// Created by hupax on 25-4-11.
//
#include <bits/stdc++.h>
using namespace std;
void init(string &s) {
    while (s.size()>1 && *s.begin()=='0') s.erase(s.begin());
}
// add  a+b
string add(string a, string b) {
    if (a.size()<b.size()) swap(a, b);
    int la=a.size(), lb=b.size();
    
    int ca=0; string res="";
    for (int i=0; i<la; i++) {
        int dta=a[la-i-1]^48;
        int dtb=i<lb?b[lb-i-1]^48:0;
        
        int sum=dta+dtb+ca;
        ca=sum/10;
        sum%=10;
        
        res+=sum^48;
    }
    if (ca>0) res+=ca^48;
    reverse(res.begin(), res.end());
    return res;
}

// sub  a-b
string sub(string a, string b) {
    string res=""; int f=0;
    // 判正负
    if (a.size()<b.size() || (a.size()==b.size() && a<b)) {
        f=1;
        swap(a, b);
    }
    
    int la=a.size(), lb=b.size();
    int br=0;
    for (int i=0; i<la; i++) {
        int dta=a[la-i-1]^48;
        int dtb=i<lb?b[lb-i-1]^48:0;
        
        int df=dta-dtb-br;
        if (df<0) df+=10, br=1;
        else br=0;
        
        res+=df^48;
    }
    
    if (f) res+='-';
    reverse(res.begin(), res.end());
    init(res);
    return res;
}

// mul a*b
string mul(string a, string b) {
    int la=a.size(), lb=b.size();
    string res(la+lb, '0');
    int ca=0;
    for (int i=la-1; i>=0; i--) {
        for (int j=lb-1; j>=0; j--) {
            int ml=(a[i]^48)*(b[j]^48)+(res[i+j+1]^48)+ca;
            res[i+j+1]=(ml%10)^48;
            ca=ml/10;
        }
        res[i]=(ca+(res[i]^48))^48;
    }
    init(res);
    return res;
}

// div a/b
string div(string a, string b) {
    if (a=="0") return "0";
    if (b=="0") return "ERROR";
    
    int la=a.size(), q=0;
    string res="", cur="";
    
    for (int i=0; i<la; i++) {
        cur+=a[i];
        q=0; // 商
        
        while ((cur.size()>b.size() || (cur.size()==b.size() && cur>=b))) {
            cur=sub(cur, b);
            q++;
        }
        
        if (res.empty() && q==0) continue;
        res+=q^48;
    }
    init(res);
    return res;
}

int main() {
    // 999099
    //  10001
    string a="0001001", b="0099909";
    init(a); init(b);
    
    cout<<add(a, b)<<endl;
    cout<<sub(a, b)<<endl;
    cout<<mul("99", "99")<<endl;
    cout<<div("12345", "15")<<endl;
    
    return 0;
}