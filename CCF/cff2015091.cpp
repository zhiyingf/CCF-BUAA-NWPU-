#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n,ans=1,x,temp;
	bool flag=true;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(i!=1&&temp!=x)ans++;
		temp=x;
	}
	printf("%d",ans);
	return 0;
}
