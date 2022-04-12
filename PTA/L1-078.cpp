#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
 
    cin >> n;
    getchar();
 
    cin >> m;
    getchar();
 
    while(n--)
    {
        string str;
        getline(cin, str);
        
        int pos1 = str.find("qiandao"); //find查找子串函数，找不到就会返回-1
        int pos2 = str.find("easy");
        
        //只要发现字符串中含有"qiandao"或"easy"，m就要减1
        if(!(pos1 != -1 || pos2 != -1)) 
        {
            m--;
            if(m < 0)
            {
                cout << str << endl;
                break;
            }
        }
    }
    
    if(m >= 0)
    {
        cout << "Wo AK le" << endl;
    }
    
    return 0;
}