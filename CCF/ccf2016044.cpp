#include<bits/stdc++.h>
using namespace std;
const int N=102;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int n,m;

struct node{
	int x,y,t;
	node(){}
	node(int _x,int _y,int _t){
		x=_x;y=_y;t=_t;
	}
};
struct point{
	int x=0,y=0;
	point(){}
	point(int _x,int _y){
		x=_x;y=_y;
	}
}g[N][N];
queue<node>que;
bool inq[N][N][N]={false};

bool test(int x,int y,int t){
	if(x<1||y<1||x>n||y>m||inq[x][y][t])return false;
	if(t>=g[x][y].x&&t<=g[x][y].y)return false;
	return true;
}

int main(){
	int v;
	scanf("%d%d%d",&n,&m,&v);
	for(int i=0;i<v;i++){
		int r,c,a,b;
		scanf("%d%d%d%d",&r,&c,&a,&b);
		g[r][c]=point(a,b);
	}
	que.push(node(1,1,0));
	inq[1][1][0]=true;
	
	while(!que.empty()){
		node top=que.front();
		que.pop();
		inq[top.x][top.y][top.t]=false;
		if(top.x==n&&top.y==m){
			printf("%d\n",top.t);
			break;
		}
		int t=top.t+1;
		for(int i=0;i<4;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(test(newX,newY,t)){
				que.push(node(newX,newY,t));
				inq[newX][newY][t]=true;
			}
		}
		
	}
	
	return 0;
}
