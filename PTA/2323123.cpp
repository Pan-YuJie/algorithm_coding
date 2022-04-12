#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int num[N];

int main()
    string s;
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }

    sort(num,num+n);

    int cnt1=1;
    for(int i=1;i<n && num[0]==num[i];i++){
        cnt1++;
    }

    int cnt2=1;
    for(int i=n-1;i>=0 && num[0]==num[i];i--){
        cnt2++;
    }

    cout<<num[0]<<' '<<cnt1<<endl;
    cout<<num[n-1]<<' '<<cnt2<<endl;
    return 0;
}