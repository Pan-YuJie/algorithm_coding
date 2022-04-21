#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    long long t;
    cin>>t;

    long long cntcong=0;
    long long cntben=0;

    int cur=0;
    int flag=0;
    int xiu=0;

    for(long long i=1;i<=t;i++){
        
        if(!flag && xiu==0){
            cntcong+=3;
            cur++;
        }
        if(flag){
            xiu--;
        }

        if(xiu==0 && flag){
            flag=0;
            xiu=0;
        }

        if(cur==3 && !flag){
            if(cntcong<cntben){
                cur=0;
                flag=0;
            }else{
                xiu=5;
                flag=1;//休息
            }
        }

        cntben+=2;

    }

    if(cntben==cntcong){
        cout<<"一样多"<<" "<<cntben;
    }else if(cntben> cntcong){
        cout<<"笨笨"<<' '<<cntben;
    }else{
        cout<<"聪聪"<<' '<<cntcong;
    }

    return 0;
}