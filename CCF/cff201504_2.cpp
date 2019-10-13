//ÔËÐÐ´íÎó70 
#include<bits/stdc++.h>
using namespace std;
int d[5004][5004];
int V;
const int INF=1000000009;
int warshall_floyd(){
	for(int k=1;k<=V;k++){
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				//printf("d[i][j]=%d ",d[i][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=V;i++){
		sort(d[i]+1,d[i]+V+1);
		if(ans<d[i][V])ans=d[i][V];
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	V=n+m;
	
	for(int i=1;i<=V;i++){
		fill(d[i]+1,d[i]+V+1,INF);
		d[i][i]=0;
	}
	
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		d[x][i]=1;
		d[i][x]=1;
	}
	for(int i=n+1;i<=V;i++){
		int x;
		scanf("%d",&x);
		d[x][i]=1;
		d[i][x]=1;
	}
	printf("%d",warshall_floyd());
	return 0; 
}
