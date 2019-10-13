#include<bits/stdc++.h>
using namespace std;
const int N=1003;
const int inf=1e8;
int g[N];


int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&g[i]);
		if(ans<g[i])ans=g[i];
	}
	int dp;
	for(int i=0;i<n;i++){
		dp=g[i];
		for(int j=i+1;j<n;j++){
			if(g[j]<dp)dp=g[j];
			if(ans<dp*(j-i+1))ans=dp*(j-i+1);
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
