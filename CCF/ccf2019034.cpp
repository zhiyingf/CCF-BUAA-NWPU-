#include<bits/stdc++.h>
using namespace std;
struct point{
	int sr;//0 s,1 r
	int x;
	point(){}
	point(int _sr,int _x):sr(_sr),x(_x){}
};
queue<point>q[10004];


int main(){
	int T,n;
	scanf("%d%d",&T,&n);
	getchar();
	while(T--){
		bool flag0=false;
		int sum=0;
		for(int i=0;i<=n;i++){
			int size=q[i].size();
			for(int j=0;j<size;j++)
			q[i].pop();
		}
		for(int k=0;k<n;k++){
			char str[50];
			cin.getline(str,50);
			for(int i=0;i<strlen(str);i++){
				int sr=1;
				if(str[i++]=='S')sr=0;
				int x=str[i++]-'0';
				q[k].push(point(sr,x));
			}
			sum+=q[k].size();
		}
		//printf("sum=%d\n",sum); 
		if(sum%2==0){
			int wait=0,begin=0;
			point p0,p1;
			while(wait<n){
				
				if(!q[begin].empty())
				p0=q[begin].front();
				else break;
				
				if(!q[p0.x].empty())
				p1=q[p0.x].front();
				else break;
				
				if(p1.x==begin){
					if((p0.sr+p1.sr)==1){
						q[begin].pop();
						q[p0.x].pop();
						sum-=2;
						if(sum==0){
							flag0=true;
							break;
						}
						while(q[begin].empty()){
							begin=(begin+1)%n;
						}
					}else{
						break;
					}
				}else{
					begin=p0.x;
					wait++;
				}
			}
		}
		if(flag0)printf("0\n");
		else printf("1\n");
		
	}
	return 0;
} 
