#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
int b[N];

int cnt=1;
int n;

void dfs(int x)
{
    if(x>n)
        return ;
    dfs(2*x);
    b[x]=cnt++;
    dfs(2*x+1);
}

int main()
{    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    dfs(1);

    for(int i=1; i<=n; i++)
        if(i==1)
            cout<<a[b[i]];
        else
            cout<<" "<<a[b[i]];
}