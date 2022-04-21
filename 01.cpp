#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000+10;
int v[MAXN];  
int w[MAXN]; 
int f[MAXN][MAXN]; 

int main() 
{
    int n, m;   
    cin >> m >> n;
    for(int i = 1; i <= n; i++) 
        cin >> v[i];
    for(int i = 1; i <= n; i++) 
        cin >> w[i];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
        {
            if(j < v[i]) 
                f[i][j] = f[i - 1][j];
            else    
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }           
    cout << f[n][m] << endl;
    return 0;
}
