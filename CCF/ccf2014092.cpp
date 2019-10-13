#include<bits/stdc++.h>
using namespace std;
struct node{
	int x1,x2,y1,y2;
	node(){}
	node(int _x1,int _y1,int _x2,int _y2){
		x1=_x1;y1=_y1;x2=_x2;y2=_y2;
	}
};

bool cmp(const node no1,const node no2){
	if(no1.x1==no2.x1){
		return no1.y1<no2.y1;
	}else{
		return no1.x1<no2.x1;
	}
}

vector<node>no;
int main(){
	int n,ans=0;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		no.push_back(node(x1,y1,x2,y2));
		ans+=(x2-x1)*(y2-y1);
	}
	
	sort(no.begin(),no.end(),cmp);
	
	
	for(int i=0;i<n;i++){
		int xx1=no[i].x1, yy1=no[i].y1, xx2=no[i].x2, yy2=no[i].y2;
		for(int j=i+1;j<n;j++){
			int x1=no[j].x1, y1=no[j].y1, x2=no[j].x2, y2=no[i].y2;
			if(xx2<=x1&&yy2<=y1)break;
			ans-=(xx2-x1)*(yy2-y1);
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
