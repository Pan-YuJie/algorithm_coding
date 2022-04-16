#include <bits/stdc++.h>
using namespace std;
int ans[1004];
int a[10005];
int n, m, s = 0, flag = 1;
void dfs(int k, int l, int sum)                
{                                             
    if (sum > m) return;
    if (sum == m) 
    {
        for (int i = 0; i < k; i++) 
        {
            if (i == k - 1)
                printf("%d\n", ans[i]);
            else
                printf("%d ", ans[i]);
        }
        flag = 0;
        return;
    }
    for (int i = l; i < n; i++) 
    {
        if (sum + a[i] <= m && flag) 
        {
            ans[k] = a[i];
            dfs(k + 1, i + 1, sum + a[i]);
        } 
        else return;
    }
}
int main() 
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        s += a[i];                       
    }
    if (s < m)
        printf("No Solution\n");
    else 
    {
        sort(a, a + n);
        dfs(0, 0, 0);
        if (flag) printf("No Solution\n");
    }
    return 0;
}
