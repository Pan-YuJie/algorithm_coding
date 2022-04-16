#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>v[N];
vector<int>men(N);
int n;
int dist[N];

void dfs(int u){
    for(int i=0;i<v[u].size();i++){
        dist[v[u][i]]=dist[u]+1;
        dfs(v[u][i]);
    }
}

int main(){
    
    
    cin>>n;
    int x,num;
    for(int i=1;i<=n;i++){    
        cin>>num;
        while(num--){
            cin>>x;
            v[i].push_back(x);
            men[x]=1;//入口为0 没被标记过
        }
    }
    
    //唯一坑的地方是 没说哪个是入口 其实很好判断 只有入口没出现在给的数据中
    //门可能不是1号
    //dfs(1);
    
    //使用find函数
    //找入口
    //返回值为迭代器类型
    auto t=find(men.begin()+1,men.begin()+n,0);
    int rukou=t-men.begin();
    dfs(rukou);
    
    cout<<max_element(dist+1,dist+n+1)-dist;
    
    return 0;
}