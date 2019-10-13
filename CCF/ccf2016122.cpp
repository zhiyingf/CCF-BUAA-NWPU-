#include<bits/stdc++.h>
using namespace std;
int a[7]={0,1500,4500,9000,35000,55000,80000};
double b[8]={1,0.97,0.9,0.8,0.75,0.7,0.65,0.55};
double c[8];

int main(){
	int T;
	double ans=3500;
	scanf("%d",&T);
	if(T<=3500)printf("%d\n",T);
	else {
		c[0]=3500;
		for(int i=1;i<7;i++){
			c[i]=(a[i]-a[i-1])*b[i];
			//printf("c[%d]=%d\n",i,c[i]);
		}
		
		int left=T-c[0];
		for(int i=1;i<7;i++){
			if(left<=c[i]){
				ans+=left*1.0/b[i];
				left=0;
				printf("%d\n",(int)ans);
				break;
			}else{
				left-=c[i];
				ans=c[0]+a[i];
			}
		}
		if(left>0){
			ans+=left*1.0/b[7];
			printf("%d\n",(int)ans);
		}
	}
	return 0;
}
