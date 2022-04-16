#include <bits/stdc++.h>
using namespace std;

vector<int> e[10010], temp, ans;
int n, maxx = -1;
bool g[10010];

void dfs(int u, int k)
{
	if (k > maxx){
	
		maxx = k;
		ans=temp;
	}

	for (int i = 0; i < e[u].size(); i++)
	{
		temp.push_back(e[u][i]);
		dfs(e[u][i], k + 1);
		temp.pop_back();
	}
	
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		while (t--)
		{
			int x;
			cin >> x;
			g[x] = 1;
			e[i].push_back(x);
		}
		sort(e[i].begin(), e[i].end());
	}
    
	int start;
	for (int i = 0; i < n; i++){
		if (g[i] == 0)
		{
			start = i;
			break;
		}
    }
    
	dfs(start, 0);
    
	printf("%d\n", maxx + 1);
	printf("%d", start);
	for (int i = 0; i < ans.size(); i++)
		printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
