#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int dis[N];
int g[N][N];
int pre[N];
int st[N];
int n,m;
int c1,c2;

void Dijkstra()
{
  memset(dis,0x3f,sizeof dis);  
   dis[c1] = 0;
   for(int i = 1;i <= n;i++){
     int t = -1;
     for(int j = 1;j <= n;j++){
         if(st[j] == false && (dis[j] < dis[t] || t==-1)){
             t = j;
         }
       }

     st[t] = true;

     for(int j = 1;j <= n;j++){
         if(dis[t] + g[t][j] < dis[j]){
             dis[j] = dis[t]+g[t][j];
             pre[j] = t;
         }
      }
 }
}

int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int x,y,w;
        cin>>x>>y>>w;
        g[y][x]=g[x][y]=w;
    }

    cin>>c1>>c2;

    Dijkstra();
    
    cout<<dis[c2]<<endl;

    stack<int>sta;

    int cur_x=c2;
    while(1){
        sta.push(cur_x);        
        if(cur_x==c1){
            break;
        }
        cur_x=pre[cur_x];
    }
    
    cout<<sta.top();
    sta.pop();
    while(sta.size()){
        cout<<"->"<<sta.top();
        sta.pop();
    }

    return 0;
}

