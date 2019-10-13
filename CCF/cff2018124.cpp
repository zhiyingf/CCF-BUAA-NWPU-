//50分 运行超时，空间不足
//使用方法：问题理解为 求最小生成树的最大边 prim算法(存储结构：邻接矩阵)，
//此算法采用贪心算法的思想，运行时间为O( n^2 )。 
#include<iostream>
#include<string>
#include<list>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int inf=1000000009;
const int maxn=10004;
bool point[maxn]; 
int low[maxn];
int gra[maxn][maxn];

int prim(int root,int n){
	int pos=root,min=inf,MST=0,temp2=0;
	for(int i=1;i<=n;i++){
		low[i]=gra[root][i];
	}
	point[pos]=true;
	for(int i=1;i<n;i++){
		min=inf;
		for(int j=1;j<=n;j++){
			if(!point[j]&&min>low[j]){
				min=low[j];
				pos=j;
			}
		}
		//printf("*%d*%d*\n",min,pos);
		point[pos]=true;
		//MST+=min;
		if(min>temp2)temp2=min;
		for(int j=1;j<=n;j++){
			if(!point[j]&&low[j]>gra[pos][j]){
				low[j]=gra[pos][j];
			}
		}
	}
	return temp2;
}
int main(){//问题定义：求最小生成树的最大边  求最小生成树的方法：kruskal,prim 
	int n,m,root;
	scanf("%d%d%d",&n,&m,&root);
	for(int i=1;i<=n;i++){
		point[i]=false;	
		for(int j=1;j<=n;j++){
			gra[i][j]=inf;
		}
	}//fill(gra[0], gra[0]+N*N, inf);//给二维数组赋值 
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&gra[x][y]);
		gra[y][x]=gra[x][y]; 
	}	
	int temp2=prim(root,n);	
	printf("%d\n",temp2);
	return 0;	
}
