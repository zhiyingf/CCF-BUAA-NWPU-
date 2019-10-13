/*
5 7
1 2 2
1 3 5
1 4 3
2 3 5
3 4 3
3 5 4
4 5 6
ans=2+3+5+4=14
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=1e8-1;
const int N=10004;
int g[N][N];
int d[N];
int dtemp[N];
bool vis[N];

int dij(int n){
	for(int i=1;i<=n;i++){
		d[i]=inf;
		dtemp[i]=inf;
		vis[i]=false;
	}
	int ans=0;
	d[1]=0;
	for(int i=0;i<n;i++){
		int min=inf,u=-1;
		for(int k=1;k<=n;k++){
			if(!vis[k]&&min>d[k]){
				min=d[k];
				u=k;
			}
		}
		if(u==-1)return 0;
		vis[u]=true;
		ans+=dtemp[u];
		//printf("min=%d  i=%d\n",min,i);
		
		for(int v=1;v<=n;v++){
				if(!vis[v]&&g[u][v]!=inf){
					if(d[v]>g[u][v]+d[u]){
					d[v]=g[u][v]+d[u];
					dtemp[v]=g[u][v];
				}else if(d[v]==g[u][v]+d[u]){
					if(dtemp[v]>g[u][v]){
						dtemp[v]=g[u][v];
					}
				}
			}
		}
	}
	return ans;
}




int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	g[i][j]=inf;
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c<g[a][b])g[a][b]=g[b][a]=c;
	}
	
	printf("%d\n",dij(n));
	
	
	return 0;
}
