
#include <iostream>
#include <cstring>
#include <map>
#include<stack>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 501;

map<string, int> mp;  //代号到数组下标的映射
map<int, string> mp2;  //数组下标映射到代号，便于后面输出路径

int n, m;//n:点的个数，m:边数
string src, des;
int g[N][N]; //邻接矩阵：存放路径长度
int army[N];//army[i]:i对应城镇的敌人数
int curarmy[N];//curarmy[i]:从src到i路径杀敌总数
int dist[N], st[N], pre[N], sum[N];
//dist[i]：src到i点的最短路长，st[i]:标记最短路径已经确定的点，pre[i]：路径的前一个点,sum[i]:src到i经过的点数
int tiao[N];//相同长度路径条数

void dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
    
	dist[0] = 0; curarmy[0] = 0; sum[0] = 0;
	tiao[0] = 1;

	for (int k = 0;k < n;k++)
	{
		int t = -1;
		for (int j = 0;j < n;j++)  //从未确定最短路径的点中找出dist最小的点
		{
			if (!st[j] &&( dist[j] < dist[t] || t==-1))
			{
				t = j;
			}
		}

		st[t] = 1; 
        
		for (int i = 0;i < n;i++)
		{
				if (dist[t] + g[t][i] < dist[i])
				{
					dist[i] = dist[t] + g[t][i];   //若从s经过点t到i点比原先短，则更新
					curarmy[i] = curarmy[t]+army[i];//顺带更新杀敌数
					pre[i] = t;                //更新前一个点
					sum[i] = sum[t] + 1;       //更新点数
					 tiao[i] =  tiao[t];//更新最短路径条数
				}
				else if (dist[t] + g[t][i] == dist[i]) 
				{
					 tiao[i] =  tiao[i] +  tiao[t];
					if (sum[i] < sum[t] + 1)    //若长度相同，但经过点数更多，也更新
					{
						curarmy[i] = curarmy[t] + army[i];
						pre[i] = t;
						sum[i] = sum[t] + 1;
					}
					else if (sum[i] == sum[t] + 1 && curarmy[i] < curarmy[t] + army[i])  //若点数也相同，杀敌数更多，也更新
					{
						curarmy[i] = curarmy[t] + army[i];
						pre[i] = t;
					}
				
			}
		}
	}
}

int main()
{
	memset(g, INF, sizeof(g));
    
	cin >> n >> m >> src >> des;
    
	mp[src] = 0;//起始点代号映射到下标0
  mp2[0]=src;
    
	string name;
	for (int i = 1;i < n;i++)
	{
		cin >> name;
		mp[name] = i;//代号映射到数组下标
		mp2[i] = name;//数组下标映射到代号，便于后面输出路径
		cin >> army[i];
	}
    
	for (int i = 0;i < m;i++)
	{
		string s, d;
		int len;
		cin >> s >> d >> len;
		g[mp[d]][mp[s]] = g[mp[s]][mp[d]] = len;
	}
    
	dijkstra();
	
    stack<string>sta;

    string cur=des;

    while(1){
        sta.push(cur);
        if(cur==src){
            break;
        }
        cur=mp2[pre[mp[cur]]];
    }

    cout<<sta.top();
    sta.pop();

    while(sta.size()){
        cout<<"->"<<sta.top();
        sta.pop();
    }
    
 	cout << endl;


	cout <<  tiao[mp[des]] << ' ' << dist[mp[des]] << ' ' <<curarmy[mp[des]];
	return 0;
}
