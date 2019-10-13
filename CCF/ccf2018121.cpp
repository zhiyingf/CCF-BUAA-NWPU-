#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,y,g,n,k,t,t1,T;
	long long ans;
	scanf("%d%d%d%d",&r,&y,&g,&n);
	T=r+y+g;
	for(int i=0;i<n;i++){
		scanf("%d%d",&k,&t);
		if(k==0){
			ans+=t;
		}else if(k==1){
			t1=ans%T;
			if(t1<t){//ºì 
				t-=t1;
				ans+=t;
			}else if(t1>=t+g&&t1<t+g+y){//»Æ 
				t=t+g+y-t1;
				ans+=t+r; 
			}else if(t1>=t+g+y){
				ans+=t+T-t1; 
			}
		}else if(k==2){
			t1=ans%T;
			if(t1<t){
				t-=t1;
				ans+=t+r;
			}else if(t1<t+r){
				t=t+r-t1;
				ans+=t;
			}else if(t1>=t+r+g){
				t=t+T-t1;
				ans+=t+r; 
			}
		}else if(k==3){
			t1=ans%T;
			if(t1>=t&&t1<t+y){
				t=t+y-t1;
				ans+=t+r; 
			}else if(t1>=t+y&&t1<t+y+r){
				t=t+y+r-t1;
				ans+=t;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
