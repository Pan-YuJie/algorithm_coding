#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>g[N];

int n;
int level[N];
int root;
int ans=1;

void BFS(){

    queue<int>q;
    q.push(root);

    while(q.size()){

        int t=q.front();
        q.pop();

        for(int i=0;i<g[t].size();i++){
            q.push(g[t][i]);
            level[g[t][i]]=level[t]+1;
            ans=max(ans,level[g[t][i]]);
        }

    }

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==-1){
            root=i;
            level[i]=1;
            continue;
        }
        g[x].push_back(i);
    }

    BFS();

    cout<<ans<<endl;
    int flag=0;
    for(int i=1;i<=n;i++){
        if(level[i]==ans){
            if(flag==0){
                cout<<i;
                flag=1;
            }
            else{
                cout<<" "<<i;
            }
        }
    }

    return 0;
}