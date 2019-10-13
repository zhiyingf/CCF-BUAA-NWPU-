#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n,ans=0,pow=10;
	scanf("%d",&n);
	while(n){		
		ans+=(n%pow)/(pow/10);
		n=n-n%pow;
		pow*=10;
	}
	printf("%d",ans);
	return 0;
}
