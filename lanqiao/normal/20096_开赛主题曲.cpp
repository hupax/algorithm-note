//
// Created by hupax on 25-4-6.
// TODO
#include <bits/stdc++.h>
#define gc getchar_unlocked()
using namespace std;
const int N=2e5+5;
int n;
char s[N];
unordered_map<string, int> mp;
string ss="lanqiobe";
auto cmp=[](string &a, string &b) {
    int na1, nb1; na1=nb1=0;
    for (char &c:a) na1+=c-'a'+1;
    for (char &c:b) nb1+=c-'a'+1;
    int k=a.size();
    while (k) {
        if (mp.count(a.substr(0, k))) {
            na1+=mp[a.substr(0, k)];
            break;
        }
        k--;
    }
  k=b.size();
  while (k) {
      if (mp.count(b.substr(0, k))) {
          nb1+=mp[b.substr(0, k)];
          break;
      }
      k--;
  }
  return na1==nb1?a<b:na1>nb1;
};
vector<string> res;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) s[i]=gc;
    int k=0;
    while (++k<=ss.size()) mp[ss.substr(0, k)]=k*10;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
        
        }
    }
    
    
    return 0;
}