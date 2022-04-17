#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
        string s;
        
        cin>>s;
        int flag=1;
        

        for(int i=0;i<s.length()-1;i++){

            if(s[i]>='a' && s[i]<='z'){ //小写
                if(s[i+1]!=toupper(s[i]) || (s[i+1]!=s[i]-1 && s[i]!='a')){
                    flag=0;
                    break;
                }

            }
            else if(s[i]>='A' && s[i]<='Z'){ //小写
                if(s[i+1]!=tolower(s[i]) || (s[i+1]!=s[i]+1 && s[i]!='z')){
                    flag=0;
                    break;
                }
            }

        }

        if(flag) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }

    return 0;
}
