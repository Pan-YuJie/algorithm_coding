#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N=510;

int n,m,start,endd;
int g[N][N];
int dist[N];//与源节点距离
int army[N];//每个城市的军队
int curarmy[N];//当前军队
int num[N];//最短路径
int st[N];

void dij(){

    memset(dist,0x3f,sizeof dist);

    dist[start]=0;
    curarmy[start]=army[start];
    num[start]=1;

    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=0;j<n;j++){
            if(!st[j] && (t==-1 || dist[j]<dist[t])){
                t=j;
            }

            if(t==-1) break;

            st[t]=true;

            //更新所有出边
            for(int j=0;j<n;j++){
                if(dist[j]>dist[t]+g[t][j]){
                    dist[j]=dist[t]+g[t][j];
                    curarmy[j]=curarmy[t]+army[j];
                    num[j]=num[t];
                }
                else if(dist[j]==dist[t]+g[t][j]){
                    num[j]+=num[t];
                    if(curarmy[j]<curarmy[t]+army[j]){
                        curarmy[j]=curarmy[t]+army[j];
                    }

                }
            }
        }
    }

}

int main(){
    
    cin>>n>>m>>start>>endd;
    
    for(int i=0;i<n;i++) cin>>army[i];
    
    memset(g,0x3f,sizeof (g));
    for(int i=0;i<m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        g[x][y]=g[y][x]=d;
    }
    
    dij();

    cout<<num[endd]<<" "<<curarmy[endd];
    return 0;
}