
#include<iostream>
#include<algorithm>
#include<memory.h> 
#include<vector>
using namespace std;

const int max_n=1e5+5;

//性别
char gender[max_n];//记录这个人的ID
int visited[max_n];//
vector<int> vec[max_n];//记录前辈 
int flag=false;

void dfs(int x,int num){
	//x表示起点，num表示向上搜的几代	
	if(num>=4) return;	//num代表查找的过程：0,1,2,3,涉及到五代 
	visited[x]=true;
	for(int i=0;i<vec[x].size();i++){
		if(!visited[vec[x][i]]){
			visited[vec[x][i]]=true;
			dfs(vec[x][i],num+1);
			//不需要回退，保留访问痕迹 
		}else{
			flag=1;//如果父亲或者母亲和之前的那个人的父母亲一样 
		}
	}
}
 
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int id,father,mother;
		char sex;
		cin>> id>>sex>>father>>mother;
		gender[id]=sex;
		if(father!=-1){
			vec[id].push_back(father);
			gender[father]='M';
		}
		if(mother!=-1){
			vec[id].push_back(mother);
			gender[mother]='F';
		}
	}
	//询问
	int m;
	cin >>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>> x>>y;
		if(gender[x]==gender[y]){
			cout<<"Never Mind"<<endl;
			continue;
		}
		//性别不同
		flag=0;
		memset(visited,false,sizeof(visited));
		dfs(x,0);//向上搜索，只要是父母，就将他们标记
		dfs(y,0);
		if(flag==1){
			//有共同的五代之内的祖先
			cout<<"No"<<endl; 
		} else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;	
}
