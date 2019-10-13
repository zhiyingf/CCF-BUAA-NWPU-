#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,c=0,ans=0;
	scanf("%d",&x);
	while(x){
		if(x==1){
			ans++;
			c=0;
		}else if(x==2){
			c++;
			ans+=c*2;
		}
		scanf("%d",&x);
	}
	printf("%d",ans);
	return 0;
} 
