#include <bits/stdc++.h>
using namespace std;
const int N=510;
int g[N][N];
int dist[N];
int num[N];
int pre[N];
int army[N];
int curarmy[N];
int n,m,s,d;
bool st[N];

void dij(){

    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    curarmy[s]=army[s];
    num[s]=1;
    
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=0;j<n;j++){
            if(!st[j] && (t==-1 || dist[j]<dist[t])){
                t=j;
            }
        }

        st[t]=true;

        for(int j=0;j<n;j++){
            if(dist[j]>dist[t]+g[t][j]){

                dist[j]=dist[t]+g[t][j];
                num[j]=num[t];
                pre[j]=t;
                curarmy[j]=curarmy[t]+army[j];

            }else if(dist[j]==dist[t]+g[t][j]){
                
                num[j]+=num[t];
                if(curarmy[j]<curarmy[t]+army[j]){
                    curarmy[j]=curarmy[t]=army[j];
                    pre[j]=t;
                }

            }
        }

    }

}

int main()
{
    
    cin>>n>>m>>s>>d;

    for(int i=0;i<n;i++) cin>>army[i];
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        g[a][b]=g[b][a]=d;
    }
    
    dij();

    cout<<num[d]<<' '<<curarmy[d]<<endl;

    stack<int>sta;

    int cur_x=d;
    while(1){
        sta.push(cur_x);        
        if(cur_x==s){
            break;
        }
        cur_x=pre[cur_x];
    }

    while(sta.size()){
        cout<<sta.top()<<' ';
        sta.pop();
    }

    return 0;
}