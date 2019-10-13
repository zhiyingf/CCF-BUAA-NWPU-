/***
单源最短路算法Bellman-Ford 
有向图 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_E=100;
const int INF=1000000009;
struct edge{//从顶点from指向顶点to的权值为cost的边 
	int from,to,cost;
};
edge es[MAX_E];//边集 
int d[MAX_E];//d[u]的u到单源点的最小距离 
int V,E;//V为顶点数，E为边数,顶点编号为1，2，。。。，n
//求解从顶点s到 所有顶点的距离 
int shortest_path(int s){
	for(int i=0;i<V;i++)d[i]=INF;
	//fill(d,d+V,INF); 
	d[s]=0;
	while(true){
		bool update=false;
		for(int i=0;i<E;i++){
			edge e=es[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
			if(!update)break;
		}
	} 
}
/***
如果在图中不存在从s可达的负圈，那么最短路不会经过同一个顶点两次（也就是说，最多经过|V|-1条边），那么while(true)
循环最多执行|V|-1次。 
如果一开始对所有的顶点i,都把d[i]初始化为0，则可以检查出所有的负圈。
如下如果返回true则存在负圈 
*/ 
bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				if(i==V-1)return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&V,&E);
	for(int i=0;i<E;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		es[i].from=x;
		es[i].to=y;
		es[i].cost=z;
	} 
	int start,end;//输入起点，终点 
	scanf("%d%d",&start,&end);
	int ans=shortest_path(start); 
	printf("%d\n",ans);
	return 0;
}
