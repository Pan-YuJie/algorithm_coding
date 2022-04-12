#include <bits/stdc++.h>
using namespace std;

int main(){

    int num[25];
    for(int i=0;i<24;i++) cin>>num[i];

    int q;
    while(cin>>q && q>=0 &&q<=23){
        cout<<num[q];
        if(num[q]>50){
            cout<<' '<<"Yes"<<endl;
        }else{
            cout<<' '<<"No"<<endl;
        }
    }

    return 0;
}