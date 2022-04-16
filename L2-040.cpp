#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int n,m;
int cun[N];

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        int x,num;
        cin>>num;
        while(num--){
            cin>>x;
            g[i].push_back(x);
        }
    }    
    int op1,op2;
    int cur=1;

    while(m--){
        cin>>op1>>op2;
        if(op1==0){ 
            cur=g[cur][op2-1];//做出选择
        }
        if(op1==1){ //存档
            cout<<cur<<endl;
            cun[op2]=cur;
        }
        if(op1==2){
            cur=cun[op2];
        }
    }
    
    cout<<cur;

    return 0;
}
