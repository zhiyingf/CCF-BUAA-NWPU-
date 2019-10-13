#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n,temp,x,ans=0,temp1;	
	scanf("%d",&n);
	scanf("%d",&temp);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		temp1=abs(x-temp);
		if(ans<temp1)ans=temp1;
		temp=x;
	}
	printf("%d",ans);
	return 0;
}
