#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n,k,x,ans=0;
	scanf("%d%d",&n,&k);
	int temp=k;
	for(int i=1;i<=n;i++){		
		scanf("%d",&x);
		if(x<temp){
			temp-=x;			
		}else{
			ans++;
			temp=k;
	    }
	}
	if(temp<k)ans++;
	printf("%d",ans);
	return 0;
}
