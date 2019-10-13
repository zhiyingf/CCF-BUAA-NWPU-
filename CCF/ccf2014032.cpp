#include<bits/stdc++.h>
using namespace std;
struct node{
	int x1,y1,x2,y2,index;
	node(){}
	node(int _x1,int _y1,int _x2,int _y2,int _index){
		x1=_x1;y1=_y1;
		x2=_x2;y2=_y2;
		index=_index;
	}
};
vector<node>ve;


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ve.push_back(node(x1,y1,x2,y2,i+1));
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		bool flag=false;
		int index;
		for(int k=n-1;k>=0&&!flag;k--){
			int x1=ve[k].x1,y1=ve[k].y1,x2=ve[k].x2,y2=ve[k].y2;
			index=ve[k].index;
			if(x<=x2&&x>=x1&&y<=y2&&y>=y1){
				flag=true;
				node no=ve[k];
				ve.erase(ve.begin()+k);
				ve.push_back(no);
				//printf("x1=%d y1=%d x2=%d y2=%d index=%d\n",x1,y1,x2,y2,index);
				break;
			}
		}
		if(flag)printf("%d\n",index);
		else printf("IGNORED\n");
	}
	return 0;
} 
