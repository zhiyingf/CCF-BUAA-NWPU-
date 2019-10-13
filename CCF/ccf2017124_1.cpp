#include<bits/stdc++.h>
using namespace std;
//1�����ݴ洢
//a.��·С·�ֿ����g[][],g0[][] 
//b.ǰ��Ϊ��·��ǰ��ΪС·�ֱ�������d[],d0[]
//c.FIFO�Ķ���queue<int>que;
//d.bool inq[]�ж϶����Ƿ��ڶ��� ;int num[]��¼ÿ��������Ӵ�����������ڶ�����-1��˵�����ڸ���

//2.˼·   ��ʼ��������  �ڽӾ������� 
//a.��ʹ��floyd���С·��ȫԴ��С·�� 
//b.����spfa 
typedef long long ll;
const int N=500+10;
const ll inf=1e18;
ll g[N][N],g0[N][N],d[N],d0[N]; 
//int num[N];
bool inq[N];
queue<int>que;

void spfa(int start , int n){
	for(int i=1;i<=n;i++)
	d[i]=d0[i]=inf,inq[i]=false;
	
	d[start]=0;
	d0[start]=0;
	que.push(start);
	inq[start]=true;
	
	while(!que.empty()){
		int u=que.front();
		que.pop();
		inq[u]=false;
		for(int i=1;i<=n;i++){
			ll v=g[u][i];
			if(d[i]>d[u]+v){//ǰ��Ϊ��·���ߴ�· 
				d[i]=d[u]+v;
				if(!inq[i]){
					que.push(i);
					inq[i]=true;
					//num[i]++;
					//if(num[i]>=n)return false;
				}
			}
			if(d[i]>d0[u]+v){//ǰ��ΪС·���ߴ�· 
				d[i]=d0[u]+v;
				if(!inq[i]){
					que.push(i);
					inq[i]=true;
				}
			}
			if(g0[u][i]!=inf){//ǰ��Ϊ��·����С· 
				v=g0[u][i]*g0[u][i];
				if(d0[i]>d[u]+v){
					d0[i]=d[u]+v;
					if(!inq[i]){
						que.push(i);
						inq[i]=true;
					}
				}
			}
		}
		
	}
}


int main(){
	int n,m;
	ll t,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g[i][j]=g0[i][j]=inf;
	
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld%lld",&t,&a,&b,&c);
		if(t&&c<g0[a][b])g0[a][b]=g0[b][a]=c;
		else if(!t&&c<g[a][b])g[a][b]=g[b][a]=c;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==i||k==j)continue;
				if(g0[i][j]>g0[i][k]+g0[k][j])g0[i][j]=g0[j][i]=g0[i][k]+g0[k][j];
			}
		}
	}
	
	spfa(1,n);
	printf("%lld\n",min(d[n],d0[n]));
	return 0;
} 
