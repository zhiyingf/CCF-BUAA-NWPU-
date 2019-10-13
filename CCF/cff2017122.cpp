#include<bits/stdc++.h>
#define rep(i,x,n) for(int i=x;i<n;i++)
using namespace std;
bool a[1003];
int main(){
	int n,k,sum=0,temp;
	scanf("%d%d",&n,&k);
	temp=n;
	fill(a,a+n,true);
	for(int i=0;temp>1;i++){
		if(a[i%n]){
			sum++;
			if(sum%k==0||sum%10==k){
				a[i%n]=false;
				temp--;
			}
		}
	}
	rep(i,0,n){
		if(a[i])
		printf("%d",i+1);
	}
	return 0;
}

