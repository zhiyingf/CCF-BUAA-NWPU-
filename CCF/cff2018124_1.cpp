//最小生成树kruskal算法+并查集，此算法采用贪心算法的思想，运行时间为O(n^2)。 
#include<iostream>
#include<string>
#include<list>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=500005;
int father[maxn];
struct edge{
	int x,y,cost;
	bool operator < (const edge &b)const{
		return cost>b.cost;//小顶堆  priority_queue内在排序默认是从大到小--大顶堆 
	}
};
priority_queue<edge> gra;
int findx(int x){
//递归实现：return x == father[x] ? x : findx(father[x]);
//非递归实现（同时简化路径）： 
	int root=x;
	while(root!=father[root]){		
		root=father[root];
	}
	while(x!=father[x]){
		x=father[x];
		father[x]=root;
	} 
	return root;
}
bool judge(int n){
	//判断是否存在最小生成树
	int flag=father[1];
	for(int i=2;i<=n;i++){
		if(flag!=findx(father[i])){
			return false;
		}
	} 
	return true;
}
int kruskal(int n){
	int temp2=0,MST=0,num=0,x,y;
	//并查集初始化
	for(int i=1;i<=n;i++){
		father[i]=i;		
	} 
	while(!gra.empty()&&num<n-1){
		edge temp=gra.top();		
		gra.pop();
		x=findx(temp.x);		
		y=findx(temp.y);	
		if(x!=y){
			father[y] = x;
			//MST+=temp.cost;
			if(temp.cost>temp2)temp2=temp.cost;
			num++;
		}
	}
	return temp2;
}
int main(){
	int n,m,root;
	scanf("%d%d%d",&n,&m,&root);
	for(int i=1;i<=m;i++){
		int x,y,cost;
		edge input;
		scanf("%d%d%d",&input.x,&input.y,&input.cost);
		gra.push(input); 
	}
	int temp2=kruskal(n);	
	printf("%d\n",temp2);
	return 0;
} 
