#include<bits/stdc++.h>
using namespace std;
float rate[8]={0,0.03,0.1,0.2,0.25,0.3,0.35,0.45};
float before[7]={3500,3500+1500,3500+4500,3500+9000,3500+35000,3500+55000,3500+80000};
float last[7];
int main(){
	int x;
	float ans;
	scanf("%d",&x);
	last[0]=3500;
	int i;
	if(x<=3500){
		printf("%d",x);
	    return 0;
	}
	for(i=1;i<7;i++){
		last[i]=last[i-1]+before[i]-before[i-1]-rate[i]*(before[i]-before[i-1]);
		//printf("\n%d\n",(int)last[i]);
		if(x<=last[i]){
			float xx=x-last[i-1];
			ans=before[i-1]+xx/(1-rate[i]);
			break;
		}
	}
	if(i==7){
		ans=before[6]+(x-last[6])/(1-rate[7]);
	}
	printf("%d",(int)ans);
	return 0;
} 
