/**
最短路径dijkstra
邻接矩阵结构： 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_V=100;
int cost[MAX_V][MAX_V];//cost[u][v]表示边e=(u,v)的权值（不存在这条边时设为INF） 
int d[MAX_V];//顶点出发的最短距离 
bool visited[MAX_V];//已使用过的图 
int V,E;//顶点数，边数 
int prev[MAX_V];//最短路上的前驱顶点 
//求从顶点出发到各个顶点之间的最短距离 
void dijstra(int s){
	fill(d,d+V,INF);
	fill(visited,visited+V,false);
	d[s]=0;
	visited[s]=true;
	while(true){
		int v=-1;
		//从尚未使用过的找出一个距离最小的定点，遍历所有未使用的顶点u的d[u] 
		for(int u=0;u<V;u++){
			if(!visited[u]&&(v==-1||d[u]<d[v]))v=u;
		}
		if(v==-1)break;//所有顶点均已遍历 
		visited[v]=true;//标记已使用 
		//使用新标记的点更新d[] 
		for(int u=0;u<V;u++){
			d[u]=min(d[u],d[v]+cost[v][u]);
			prev[u]=v; 
		} 
	}
}

vector<int> get_path(int t){
	vector<int> path;
	for(;t!=-1;t=prev[t])path.push_back(t);
	reverse(path.begin(),path.end());
	return path;
}

/**
最短路径dijkstra
邻接矩阵结构：
*/ 
struct edge{
	int to,cost;
};
typedef pair<int,int> P;

int V,E;
vector<edge> G[MAX_V];//from
int d[MAX_V];

void dijstra(int s){
	//通过指定greater<P>参数，优先队列中的堆会按照pair的first从小到大的顺序取出值
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(int u=0;u<G[v].size();u++){
			edge e=G[v][i];//from to
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to))
			}
		}
	} 
}


int main(){
	int 
} 
