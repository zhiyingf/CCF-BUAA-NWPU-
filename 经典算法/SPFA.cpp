#include<bits/stdc++.h>
using namespace std;
const int MAX_V=302;
int a[MAX_V];
struct edge{
	int to,cost;
};
vector<edge>gra[MAX_V];//аз╫с╠М 
queue<int> que;
int d[MAX_V];
bool inside[MAX_V];
int in[MAX_V];
int V;
void add_edge(int x,int y,int v){
	edge e;
	e.cost=v;e.to=y;
	gra[x].push_back(e);
}
bool SPFA(){
	for(int i=0;i<=V;i++){
		inside[i]=true;
	    in[i]=1;
	    d[i]=0;
	    que.push(i);
	}
	while(!que.empty()){
		int v=que.front();
		que.pop();
		inside[v]=false;
		if(++in[v]>V)return false;
		for(int u=0;u<gra[v].size();u++){
			edge e=gra[v][u];
			if(d[e.to]<d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				if(!inside[e.to]){
					inside[e.to]=true;
					que.push(u);					
				}
			}
		}
	}
	return true;
} 
int main(){
	scanf("%d",&V);
	for(int i=1;i<=V;i++){
		scanf("%d",&a[i]);
		if(i==1||i==V)a[i]*=2;
		else a[i]*=3;
	}
	add_edge(2,0,-(a[1]+1));
	add_edge(0,2,a[1]);
	for(int i=1;i+3<=V;i++){
		add_edge(i+3,i,-(a[i+2]+2));
	    add_edge(i,i+3,a[i+2]);
	}
	add_edge(V,V-2,-(a[V]+1));
	add_edge(V-2,V,a[V]*2);
	for(int i=0;i+1<=V;i++){
		add_edge(i,i+1,1);
	}
	SPFA();
	printf("%d",d[1]);
	for(int i=2;i<=V;i++){
		printf(" %d",d[i]-d[i-1]);
	}
	return 0;
}
