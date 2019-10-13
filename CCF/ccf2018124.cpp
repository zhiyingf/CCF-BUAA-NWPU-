#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct edge{
	int u,v,c;
	bool operator <(const edge &a)const{
		return c<a.c;
	}
}g[N];
int uf[N];
int find(int x){
	if(uf[x]==-1)return x;
	else return uf[x]=find(uf[x]);
}

int main(){
	int n,m,r;
	scanf("%d%d%d",&n,&m,&r);
	memset(uf,-1,sizeof(uf));
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&g[i].v,&g[i].u,&g[i].c);
	}
	sort(g,g+m);
	int cnt=0,ans=0;
	for(int i=0;i<m;i++){
		int u=g[i].u;
		int v=g[i].v;
		int c=g[i].c;
		int fu=find(u);
		int fv=find(v);
		if(fu!=fv){
			fu=uf[fv];
			ans=max(ans,c);
			cnt++;
			if(cnt==n-1)break;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
