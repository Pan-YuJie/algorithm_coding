#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 30;

struct node{ 
	int data;
	node* lchild;
	node* rchild;
};
int n,post[maxn],in[maxn];//结点数、后序序列、中序序列 

node* create(int postL,int postR,int inL,int inR){//依据后序序列和中序序列构建唯一的二叉树 
	if(postL>postR) return NULL; 
	node* root = new node;
	root->data = post[postR];
	int k;//根结点所在位置 
	for(k=inL;k<inR;k++){
		if(in[k]==post[postR])
			break;
	}
	int numLeft = k-inL;//左子树结点数
	root->lchild = create(postL,postL+numLeft-1,inL,k-1);//递归式 
	root->rchild = create(postL+numLeft,postR-1,k+1,inR);//递归式 
	return root;
}

void dfs(node* root){

    if(root==NULL) return ;

    cout<<" "<<root->data;
    dfs(root->lchild);
}

void dfsr(node* root){

    if(root==NULL) return ;

    cout<<" "<<root->data;
    dfsr(root->rchild);
}

int main(){
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) scanf("%d",&post[i]);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	node* root = create(0,n-1,0,n-1); 

    cout<<"R:";
    dfsr(root);

    cout<<endl;

    cout<<"L:";
    dfs(root);
	return 0;	
}
