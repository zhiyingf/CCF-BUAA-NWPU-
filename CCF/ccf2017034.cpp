#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct edge{
	int to;
	int dist;
	edge(int _to,int _dist):to(_to),dist(_dist){
	}
}; 
vector<edge>g[N];
bool inq[N];
queue<int>que;
int d[N];

int main(){
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back(edge(b,c));
		g[b].push_back(edge(a,c));
	}
	
	fill(inq,inq+n+1,false);
	memset(d,-1,sizeof(d));
	que.push(1);
	inq[1]=true;
	d[1]=0;
	
	while(!que.empty()){
		int u=que.front();
		que.pop();
		inq[u]=false;
		
		int size=g[u].size();
		
		for(int i=0;i<size;i++){
			if(d[g[u][i].to]==-1||d[g[u][i].to]>max(d[u],g[u][i].dist)){
				d[g[u][i].to]=max(d[u],g[u][i].dist);
				if(!inq[g[u][i].to]){
					que.push(g[u][i].to);
					inq[g[u][i].to]=true;
				}
			}
		}
		
	}
	printf("%d\n",d[n]);
	
	return 0;
}
