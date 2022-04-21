#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int students[N];
int sandwiches[N];
int n;

int countStudents(){
    int arr[2] = {0};
    for(int i=0;i<n;i++)
    {
        arr[students[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[sandwiches[i]]==0)
        {
            break;
        }
        arr[sandwiches[i]]--;//吃掉
    }
    return arr[0]+arr[1];
}

int main()
{

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>students[i];
    }
    for(int i=0;i<n;i++){
        cin>>sandwiches[i];
    }

    cout<<countStudents();
    return 0;
}