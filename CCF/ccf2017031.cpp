#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,ans=0,temp=0,x;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(temp==0){
			if(x>=k){
				ans++;
			}else temp+=x;
		}else{
			temp+=x;
			if(temp>=k){
				ans++;
				temp=0;
			}
		}
	}
	if(temp>0)ans++;
	printf("%d\n",ans);
	return 0;
}
