#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[1003];
int main(){
	int n,temp=10004,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int j=i-1;
		while(j>0&&temp){
			ans=abs(a[i]-a[j]);
			if(ans<temp)temp=ans;
			j--;
		}
	}
	printf("%d",temp);
	return 0;
}
