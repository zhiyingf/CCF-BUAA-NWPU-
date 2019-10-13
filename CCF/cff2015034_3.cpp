//70‘À––≥¨ ± 
#include<bits/stdc++.h>
using namespace std;
const int INF=1000000009;
typedef pair<int,int> P;
int V;
vector<int>gra[20004];
int d[20004];
int dij(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d+1,d+V+1,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(int u=0;u<gra[v].size();u++){
			int e=gra[v][u];
			if(d[e]>d[v]+1){
				d[e]=d[v]+1;
				que.push(P(d[e],e));
			}
		}
	}
	//sort(d+1,d+V+1);
	//return d[V];
	int ans=0,temp=0;
	for(int i=1;i<=V;i++){
		if(ans<d[i]){
			temp=i;
			ans=d[i];
		}
	}
	return temp; 
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	V=n+m;
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		gra[x].push_back(i);
		gra[i].push_back(x);
	}
	for(int i=n+1;i<=(n+m);i++){
		int x;
		scanf("%d",&x);
		gra[x].push_back(i);
		gra[i].push_back(x);
	}
	int ans=0;
	int aa=dij(n+1);
	aa=dij(aa);
	printf("%d",d[aa]); 
	//printf("%d",dij(V));
	return 0;
}
