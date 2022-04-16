#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int flag[N];
int f[N];
int num[N];
bool cmp(int x,int y){
    return x>y;
}

int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

void mer(int a,int b){

    int x=find(a);
    int y=find(b);
    if(x!=y){
        f[y]=x;
    }

}

void init() {
    for (int i = 1; i <= n; i++) { //注意
        f[i] = i;
    }
}

int main()
{
    cin>>n;
    init();
    char ch;
    for(int i=1;i<=n;i++){
        int x,num;
        cin>>num>>ch;
        while(num--){
            cin>>x;
            if(!flag[x]){
                flag[x]=i;
            }
            else{
                mer(i,flag[x]);
            }
        }
    }


    for(int i=1;i<=n;i++){
        num[find(i)]++;
    }
    
    int cnt=0;
    for (int i = 1; i <=n; i++)
    {
        if(num[i]) cnt++;
    }
    
    cout<<cnt<<endl;

    sort(num+1,num+1+n,cmp);//降序

    cout<<num[1];
    for(int i=2;i<=n;i++){
        if(num[i])
        cout<<" "<<num[i];
        else
        break;
    }

    
    return 0;
}
