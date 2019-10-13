
#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<vector>

#include<queue>

using namespace std;

const int N=1e4+10;

const int inf=1e8-1;

struct edge

{

	int to;

	int cost;

	edge(){}

	edge(int a,int b)

	{

		to=a;

		cost=b;

	}

};

struct node

{

	int id;

	int cost;

	node(int a,int b)

	{

		id=a;cost=b;

	}

	bool operator < (const node &u) const

	{

		return cost>u.cost;

	}

};

vector<edge> g[N];

int dist[N],f[N]; //f[]数组存储到每个节点的单条路径花费

int n,m;

void init()

{

	for(int i=0;i<=n;i++)

	dist[i]=f[i]=inf;

	dist[1]=0;

}

void dj()

{

	priority_queue<node> q;

	q.push(node(1,0));

	while(!q.empty())

	{

		node x=q.top();

		q.pop();

		int u=x.id;

		int t=x.cost;

		int l=g[u].size();

		for(int i=0;i<l;i++)

		{

			if(dist[g[u][i].to]>dist[u]+g[u][i].cost||dist[g[u][i].to]==dist[u]+g[u][i].cost&&f[g[u][i].to]>g[u][i].cost) //更短路或者是同短路加花费更小

			{

				dist[g[u][i].to]=dist[u]+g[u][i].cost;

				q.push(node(g[u][i].to,dist[g[u][i].to]));

				f[g[u][i].to]=g[u][i].cost; //更新花费

			}

		}

	}

}

int main()

{

	int a,b,c;

	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++)

	{

		scanf("%d%d%d",&a,&b,&c);

		g[a].push_back(edge(b,c));

		g[b].push_back(edge(a,c));

	}

	init();

	dj();

	int ans=0;

	for(int i=2;i<=n;i++)

	ans+=f[i];

	printf("%d\n",ans);

	return 0;

}

