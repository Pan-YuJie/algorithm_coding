#include <iostream>
using namespace std;
const int N = 100010;

struct Node
{
    double x;
    double y;
}node[N];


int main(){

    int n;
    double v;
    int idx=0;
    cin>>n>>v;

    for(int i=0;i<n;i++){
        double t,b;
        cin>>t>>b;
        node[idx].x=t;
        node[idx++].y=b;
    }

    int i=0;
    while(n--){
        double vv;
        cin>>vv;
        printf("%.3lf ",node[i].x-(node[i].y/vv));
        i++;
    }

    return 0;
}