#include <bits/stdc++.h>
using namespace std;
const int N=200;
int a[N][N];
int b[N][N];
int n,x,k;


int main()
{
    
    cin>>n>>k>>x;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }

    int cnt=1;
    //int row=2;
    for(int i=2;i<=n;i+=2){ //列
        for(int cur=1;cur<=n;cur++){ //caozuo
            if(cur<=cnt){
                b[cur][i]=x;
            }
            else{
                b[cur][i]=a[cur-cnt][i];
            }
        }
            cnt++;
            if(cnt>k){
                cnt=1;
            }
    }
    int flag=1;

    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=b[i][j];
        }
        if(flag==1){
            cout<<sum;
            flag=0;
        }
        else cout<<' '<<sum;
    }

    return 0;
}