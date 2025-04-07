//
// Created by hupax on 25-4-6.
//
#include <iostream>
using namespace std;
int q, a2, a3, a4, b4, b6, ans;
int main() {
    cin>>q;
    while (q--) {
        cin>>a2>>a3>>a4>>b4>>b6;
        ans=0;
        while (b6>0) {
            if (a3>=2) a3-=2, b6--;
            else if (a2>=3) a2-=3, b6--;
            else if (a4 && a2) a4--, a2--, b6--;
            else break;
            ans+=6;
        }
        while (b4>0) {
            if (a4) a4--, b4--;
            else if (a2>=2) a2-=2, b4--;
            else break;
            ans+=4;
        }
        while (b6>0) {
            if (a2 && a3) a2--, a3--, ans+=5;
            else if (a4) a4--, ans+=4;
            else if (a3) a3--, ans+=3;
            else if (a2) a2--, ans+=2;
            b6--;
        }
        while (b4>0) {
            if (a4) a4--, ans+=4;
            else if (a3) a3--, ans+=3;
            else if (a2) a2--, ans+=2;
            b4--;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}