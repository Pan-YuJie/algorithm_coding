#include<bits/stdc++.h>
using namespace std;
int n,ans,x,t;

int level[100010];
vector<int>G[100010];

void DFS(int x,int step)
{
    ans=max(ans,step);
    for(int i=0;i<G[x].size();i++)
    {
        level[G[x][i]]=step+1;
        DFS(G[x][i],step+1);
    }
    return ;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==-1)
        {
            x=i;
            level[i]=1;
            continue;
        }
        G[t].push_back(i);
    }
    
    DFS(x,1);
    
    cout<<ans<<endl;
    
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(level[i]==ans)
        {
            if(flag==0)
                cout<<i,flag=1;
            else
                cout<<" "<<i;
        }
    }
    cout<<endl;
    return 0;
}
