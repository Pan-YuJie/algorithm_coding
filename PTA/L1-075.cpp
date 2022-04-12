#include <bits/stdc++.h>
using namespace std;
int x;

int main(){
    string s;
    cin>> s;

    if(s.length()==6){
        for(int i=0;i<s.length();i++){
            if(i==4){
                cout<<"-";
            }
            cout<<s[i];
        }
    }else{
        int num=stol(s.substr(0,2));
        if(num<22){
            cout<<"20"+s.substr(0,2)+"-"+s.substr(2);
        }else{
            cout<<"19"+s.substr(0,2)+"-"+s.substr(2);
        }
    }
    
    return 0;
}