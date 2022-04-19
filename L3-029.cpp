#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
int n,m;
vector<int> v[maxn], v1;
bool vis[maxn];
int h[maxn];
void dfs(int x){//x是当前纸条的下标
    if(x>=n-1){//终止条件
        for (int i = 0; i < v1.size();i++){//遍历输出
            if(i)
                cout << " ";
            cout << v1[i];
        }
    }
    for (int i = 1; i <= m; i++){
        if(!vis[i]){//当前纸条未使用过
            int flag = 1;
            for (int j = 0; j < v[i].size();j++){
                if(v[i][j]!=h[x+j])
                    flag = 0;//不满足题意
            }
            if(flag){
                cout<<i<<endl;
                v1.push_back(i);
                vis[i] = 1;
                dfs(x + v[i].size()-1);
                vis[i] = 0;//回溯
                v1.pop_back();//回溯
            }
        }
    }
}
void solve(){
    cin >> n;
    for (int i = 1;i<=n;i++){
        cin >> h[i];
    }
    cin >> m;
    
    for (int i = 1;i<=m;i++){
        int k, x;
        cin>>k;
        while(k--){
            cin>>x;
            v[i].push_back(x);
        }
    }
    dfs(1);
}
int main(){
    solve();
    return 0;
}

