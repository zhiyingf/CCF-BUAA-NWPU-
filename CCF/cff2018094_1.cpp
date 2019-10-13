#include<iostream>
#include<queue>
#include<cstring>
#define rep(i,x,n) for(int i=x;i<n;i++)
using namespace std;
//head
struct edge{int to,cost;};
vector<edge>gra[306];//邻接表 
int n,cur=0,a[306],head[306],dist[306],inq[306],vis[306];
void addedge(int x,int y,int v){
	edge e;
	e.cost=v;e.to=y;
	gra[x].push_back(e);
}
void spfa()
{
     queue<int>qq;
     rep(i,0,n+1)
     {qq.push(i);vis[i]=1;dist[i]=0;inq[i]=1;}
     while(!qq.empty())
     {
         int x=qq.front();
         qq.pop();
         //inq[x]++;
         vis[x]=0;
         //if(inq[x]>n){cout<<"noanswer"<<endl;return ;}
         for(int u=0;u<gra[x].size();u++){
			edge e=gra[x][u];
			if(dist[e.to]<dist[x]+e.cost){
				dist[e.to]=dist[x]+e.cost;
				if(!vis[e.to])
                 {
                     vis[e.to]=1;
                     qq.push(e.to);
                     if(++inq[e.to]>n){cout<<"noanswer"<<endl;return ;}
                 }
			}
		}
     }
     return ;
}
int main()
{
     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     memset(head,-1,sizeof(head));
     cin>>n;
     rep(i,1,n+1)cin>>a[i];
     rep(i,0,n-2){addedge(i+3,i,-(a[i+2]*3+2));addedge(i,i+3,a[i+2]*3);}
     addedge(2,0,-(a[1]*2+1));addedge(0,2,a[1]*2);   //对开始两个单独处理
     addedge(n,n-2,-(a[n]*2+1));addedge(n-2,n,a[n]*2);  //对结尾两个单独处理
     rep(i,1,n+1)addedge(i-1,i,1);              //每个数都要大于等于1
     spfa();
     a[1]=dist[1];
     rep(i,2,n+1)a[i]=dist[i]-dist[i-1];
     cout<<a[1];rep(i,2,n+1)cout<<' '<<a[i];
     return 0;
}

