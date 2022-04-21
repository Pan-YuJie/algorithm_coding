#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>g[N];
int n,m,k;
int color[N];
int flag;

void solve(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(color[i]==color[g[i][j]]){
				flag=0;
				return;
			}
		}
	}
}
int main()
{
	
	cin>>n>>m>>k;

	while(m--){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int num;
	cin>>num;
	set<int>st;
	while(num--){
		st.clear();
		for(int i=1;i<=n;i++){
			int s;
			cin>>s;
			color[i]=s;
			st.insert(s);
		}

		if(st.size()!=k){
			cout<<"No"<<endl;
			continue;
		}
		flag=1;
		solve();
		if(flag){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}

	return 0;
}