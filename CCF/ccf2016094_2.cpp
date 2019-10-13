/*
5 7
1 2 2
1 3 5
1 4 3
2 3 5
3 4 3
3 5 4
4 5 6
ans=2+3+5+4=14
���ˣ��ŷ��ֲ��ܿ��ü���1e7���ϴ�����飬int ab[10000][10000]�����ʣ���ʱ��Ӧ�����ڽӱ�洢ͼ��
ע�⣺�������д��󣬿��ܲ������˼·���ˣ�Ҳ�����������⣬��Ӧ���ǿ���������ڴ泬�ˣ�����
ע�⣡����ʱ��������1s���ڴ�������256MB=2e18B��Ҳ�Ͳ��2e7B���ҵĴ�ɣ������ܿ�1e7���ϴ������ 


*/

#include<bits/stdc++.h>
using namespace std;
const int inf=1e8-1;
const int N=10004;
//int g[N][N];
struct point{
	int to,cost;
	point(){}
	point(int _to,int _cost):to(_to),cost(_cost){}
};
vector<point>g[N];
int d[N];
int dtemp[N];
bool vis[N];

int dij(int n){
	for(int i=1;i<=n;i++){
		d[i]=inf;
		dtemp[i]=0;
		vis[i]=false;
	}
	int ans=0;
	d[1]=0;
	for(int i=0;i<n;i++){
		int min=inf,u=-1;
		for(int k=1;k<=n;k++){
			if(!vis[k]&&min>d[k]){
				min=d[k];
				u=k;
			}
		}
		if(u==-1)return 0;
		vis[u]=true;
		ans+=dtemp[u];
		//printf("min=%d  i=%d\n",min,i);
		
		for(int k=0;k<g[u].size();k++){
			int v=g[u][k].to,cost=g[u][k].cost;
				if(!vis[v]){
					if(d[v]>cost+d[u]){
					d[v]=cost+d[u];
					dtemp[v]=cost;
				}else if(d[v]==cost+d[u]){
					if(dtemp[v]>cost){
						dtemp[v]=cost;
					}
				}
			}
		}
	}
	return ans;
}




int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back(point(b,c));
		g[b].push_back(point(a,c));
	}
	
	printf("%d\n",dij(n));
	
	
	return 0;
}
