#include<iostream>
#include<string>
#include<list>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int a[1003];
int aa[1003];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	aa[1]=(a[1]+a[2])/2;
	aa[n]=(a[n-1]+a[n])/2;
	printf("%d ",aa[1]);
	for(int i=2;i<n;i++){
		    aa[i]=(a[i-1]+a[i]+a[i+1])/3;
		    printf("%d ",aa[i]);
	}
	printf("%d",aa[n]);	
	return 0;
}
