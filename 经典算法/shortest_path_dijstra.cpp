/**
���·��dijkstra
�ڽӾ���ṹ�� 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_V=100;
int cost[MAX_V][MAX_V];//cost[u][v]��ʾ��e=(u,v)��Ȩֵ��������������ʱ��ΪINF�� 
int d[MAX_V];//�����������̾��� 
bool visited[MAX_V];//��ʹ�ù���ͼ 
int V,E;//������������ 
int prev[MAX_V];//���·�ϵ�ǰ������ 
//��Ӷ����������������֮�����̾��� 
void dijstra(int s){
	fill(d,d+V,INF);
	fill(visited,visited+V,false);
	d[s]=0;
	visited[s]=true;
	while(true){
		int v=-1;
		//����δʹ�ù����ҳ�һ��������С�Ķ��㣬��������δʹ�õĶ���u��d[u] 
		for(int u=0;u<V;u++){
			if(!visited[u]&&(v==-1||d[u]<d[v]))v=u;
		}
		if(v==-1)break;//���ж�����ѱ��� 
		visited[v]=true;//�����ʹ�� 
		//ʹ���±�ǵĵ����d[] 
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
���·��dijkstra
�ڽӾ���ṹ��
*/ 
struct edge{
	int to,cost;
};
typedef pair<int,int> P;

int V,E;
vector<edge> G[MAX_V];//from
int d[MAX_V];

void dijstra(int s){
	//ͨ��ָ��greater<P>���������ȶ����еĶѻᰴ��pair��first��С�����˳��ȡ��ֵ
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
