#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int f[N];
int cnt[N];
int n,m;
int person[N];

int find(int x){
    if(f[x]!=x) return f[x]=find(f[x]);
    return x;
}

void mer(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b){
        f[b]=a;
    }
}

bool cmp(int x,int y){
  return x>y;
}

int main()
{       

    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        f[i]=i;
    }

    while(m--){
        int x,y;
        cin>>x>>y;
        mer(x,y);
    }
    
    int k;
    cin>>k;
    int yy=k;
    int idx=1;
    int mmax=-1;
    int id;
    while(yy--){
        int t;
        cin>>t;
        cnt[find(t)]++;
        if(cnt[find(t)]>cnt[mmax]){
          mmax=find(t);
        }
        person[idx++]=find(t);
    }
    
    sort(cnt+1,cnt+n+1,cmp);
    
    int flag=0;
    

    for(int i=1;i<=k;i++){
      if(person[i]==mmax){
        cout<<i<<' ';
      }
      
    }

    return 0;
}