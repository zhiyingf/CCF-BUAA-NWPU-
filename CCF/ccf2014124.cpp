#include<bits/stdc++.h>
using namespace std;
const int N=1003;
const int inf=1e9;
int g[N][N];
int d[N];
bool vis[N];

void dij(int s,int n){
	for(int i=1;i<=n;i++){
		d[i]=inf;
		vis[i]=false;
	}
	
	d[s]=0;
	
	for(int i=0;i<n;i++){//循环n次 
		int min=inf,u=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&min>d[i]){
				min=d[i];
				u=i;
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&g[u][i]!=inf&&d[i]>d[u]+g[u][i]){
				d[i]=d[u]+g[u][i];
			}
		}
	}
	
}

int prim(int s,int n){
	int ans=0;
	for(int i=1;i<=n;i++){
		d[i]=inf;
		vis[i]=false;
	}
	
	d[s]=0;
	
	for(int i=0;i<n;i++){//循环n次 
		int min=inf,u=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&min>d[i]){
				min=d[i];
				u=i;
			}
		}
		if(u==-1)return 0;
		vis[u]=true;
		ans+=min;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&g[u][i]!=inf&&d[i]>g[u][i]){
				d[i]=g[u][i];
			}
		}
	}
	return ans;
}


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g[i][j]=g[j][i]=inf;
	
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c<g[a][b]){
			g[a][b]=g[b][a]=c;
		}
	}
	
	printf("%d\n",prim(1,n));
	
	return 0;
}
