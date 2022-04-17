#include <bits/stdc++.h>
using namespace std;
const int N=1e6;

struct Node{
    int cnt;
    string name;
    double avg;
}node[N];

bool cmp(struct Node x,struct Node y){
    if(x.cnt!=y.cnt)
    return x.cnt>y.cnt;
    return x.cnt<y.cnt;
}

int main()
{

  int n;
  cin>>n;
  int idx=0;

  while(n--){
      string s;
      int num,x;
      cin>>s>>num;
      set<int>st;
      while(num--){
          cin>>x;
          st.insert(x);
      }

      node[idx].name=s;
      node[idx].cnt=st.size();
      node[idx++].avg=num*1.0/st.size();

  }  

    sort(node,node+idx,cmp);
    int flag=0;

    for(int i=0;i<3;i++){
        if(flag==0){
        if(idx<i) cout<<'-';
        else cout<<node[i].name;
        }else{
            if(idx<i) cout<<" "<<'-';
            else cout<<" "<<node[i].name;
        }
    }

    return 0;
}