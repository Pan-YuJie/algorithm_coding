#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<string>bian;
set<string>st;
stack<int>sta;
map<string,int>mp;

int main()
{
    
    int n,m;

    cin>>n>>m;
    int idx=0;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        bian.push_back(s);
    } 
    
    for(int i=0;i<n/m;i++){
        int num;
        for(int i=0;i<m;i++){
            cin>>num;
            sta.push(num);
        }

        while(sta.size()){
            mp[bian[idx++]]=sta.top();
            sta.pop();
        }

    }

    cin>>m;

    while(m--){
        string q;
        cin>>q;
        if(!mp[q]){
            cout<<"Wrong Number"<<endl;
        }else{
            cout<<mp[q]<<endl;
        }
    }

    return 0;
}