#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n,ans=0;
	scanf("%d",&n);
	ans+=(n/50)*7;//5+2
	n=n%50;
	ans+=(n/30)*4;//3+1
	n=n%30;
	ans+=(n/10)*1; 
	printf("%d",ans);
	return 0;
}
