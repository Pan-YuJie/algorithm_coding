#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>v(N);
map<vector<int>,int>ying;

struct node
{
    vector<int>t;
    int cnt;
}Node[N];

bool cmp(struct node x,struct node y){
    if(x.cnt!=y.cnt)
        return x.cnt>y.cnt;
    else{
        for(int i=0;i<x.t.size();i++){
            if(x.t[i]<y.t[i]){
                return 1;
            }
            if(x.t[i]>y.t[i]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    int n,m;
    cin>>n>>m;
    int idx=1;

    while(n--){
        v.clear();
        for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    if(!ying[v]){//没有找到
        ying[v]=idx;
        //ying.insert(make_pair(v,idx));
        Node[idx].t=v;
        Node[idx].cnt=1;
        idx++;
    }else{
        Node[ying[v]].cnt++;
    }

    }
    
    sort(Node+1,Node+idx+1,cmp);

    printf("%d\n",idx-1);

    for(int i=1;i<idx;i++)
    {
        printf("%d ",Node[i].cnt);
        for(int j=0;j<Node[i].t.size();j++)
        {
            if(j!=0)
                printf(" ");
            printf("%d",Node[i].t[j]);
        }
        cout<<endl;
    }

    return 0;
}