#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[1003];
int b[1003]={0};
int main(){
	int n;
	bool flag=false;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int x,y,i;
	for(i=1;i<=n;i++){
		x=0;y=0;
		for(int j=1;j<=n;j++){
			if(a[i]<a[j])x++;
			else if(a[i]>a[j])y++;
		}
		if(x==y){
			if(!b[a[i]]){
				if(flag)printf(" ");
				printf("%d",a[i]);
			}
			flag=true;
			b[a[i]]=1;									
			//break;
		}
	}
	if(!flag)
	printf("-1");
	//printf("\n%d",i);
	//printf("\n%d",x);
	//printf("\n%d",y);
	return 0;
}
