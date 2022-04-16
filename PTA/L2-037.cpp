#include <bits/stdc++.h>

using namespace std;

int n,m,s,t;
stack<char> st[105],k;

int main()
{
	cin>>n>>m>>s;

    //轨道物品
	for(int i=1;i<=n;++i)
	{
		string str;cin>>str;
		for(int j=m-1;j>=0;--j)st[i].push(str[j]);
	}

	while(cin>>t)
	{
		if(t==-1)break;

		if(t==0)
		{
			if(k.size()==0)continue;
			cout<<k.top();k.pop(); 
		}
		else 
		{
			if(st[t].empty())continue;
			if(k.size()==s)
			{
				cout<<k.top();k.pop();
			}
			char x=st[t].top();st[t].pop();
			k.push(x);
		}
	}
	return 0;
}
