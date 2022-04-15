#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int g[N][N];
int ans;
int n,m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int tmp;
bool st[N][N];

void dfs(int x,int y,int tmp){
  
  if(x==n-1 && y== m-1){
    ans=min(tmp,ans);
    return;
  }
  
  for(int i=0;i<4;i++){
    
    int nx=x+dx[i];
    int ny=y+dy[i];
    
    if(nx<0 || nx>=n || ny<0 || ny>= m || st[nx][ny]){
      continue;
    }
    
    if(nx!=n-1 && ny!=m-1){
      st[nx][ny]=true;
    }
    tmp=max(abs(g[x][y]-g[nx][ny]),tmp);
    dfs(nx,ny,tmp);
  }
  
}

int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> g[i][j];
      }
    }
    
    dfs(0,0,-1);

    cout << ans;
    
    return 0;

}