//ºú·²p380 
#include<bits/stdc++.h>
using namespace std;
int save[502],d[502],w[502],num[502];
int g[502][502];
bool vis[502]={false};
const int inf=(1<<30)-1;

int dij(int start,int n){
	fill(d,d+502,inf);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	
	d[start]=0;
	//vis[start]=true;
	w[start]=save[start];
	num[start]=1;
	
	for(int i=0;i<n;i++){
		int min=inf,u=-1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)return 0;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(!vis[v]&&g[u][v]!=inf){
				if(d[u]+g[u][v]<d[v]){
					d[v]=d[u]+g[u][v];
					w[v]=w[u]+save[v];
					num[v]=num[u];
				}else if(d[u]+g[u][v]==d[v]){
					if(w[u]+save[v]>w[v]){
						w[v]=w[u]+save[v];
					}
					num[v]+=num[u];
				}
			}
		}
		
	}
	
	return 0;
}

int main(){
	int n,m,c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	fill(g[0],g[0]+502*502,inf);
	for(int i=0;i<n;i++){
		scanf("%d",&save[i]);
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(g[a][b]>c){
			g[a][b]=g[b][a]=c;
		}
	}
	dij(c1,n);
	printf("%d %d\n",num[c2],w[c2]);
	return 0;
}
