#include <bits/stdc++.h>
using namespace std;

int main(){

    double num;
    double cost;
    cin>>num>>cost;
    double cur;
    while(num--){
        cin>>cur;
        if(cur<cost){
            cout<<"On Sale! ";
            printf("%.1lf\n",cur);
        }
    }

    return 0;
}