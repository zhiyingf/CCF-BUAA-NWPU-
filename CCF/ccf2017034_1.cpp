#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<queue>

#include<vector>

using namespace std;

const int N=1e5+10;

//ͼ�Ĵ洢�ṹ���ڽӱ� 

struct edge

{

	int to;//ĩ�˽ڵ� 

	int dist;//���� 

	edge(int a,int b)

	{

		to=a;

		dist=b;

	}

};

vector<edge> g[N];

int vis[N];//��¼��ǰ���ıߣ������� 

int n,m;

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

	memset(vis,-1,sizeof(vis));

	queue<int> q;

	q.push(1);

	vis[1]=0;

	while(!q.empty())

	{

		int u=q.front();

		q.pop();

		int l=g[u].size();

		for(int i=0;i<l;i++)

		{

			if(vis[g[u][i].to]==-1||vis[g[u][i].to]>max(vis[u],g[u][i].dist))

			{

				vis[g[u][i].to]=max(vis[u],g[u][i].dist);

				q.push(g[u][i].to);

			}

		}

	}

	printf("%d\n",vis[n]);

	return 0;

}

