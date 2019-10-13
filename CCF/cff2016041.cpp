#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[1003];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<n;i++){
		if(a[i-1]<a[i]&&a[i]>a[i+1]){
			ans++;
		}else if(a[i-1]>a[i]&&a[i+1]>a[i]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
