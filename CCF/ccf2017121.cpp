#include<bits/stdc++.h>
using namespace std;
int ab[1003];
const int INF=(1<<30)-1;
int main(){
	int n,ans=INF;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&ab[i]);
	}
	sort(ab,ab+n);
	for(int i=n-1;i>0;i--){
		int temp=ab[i]-ab[i-1];
		if(temp<ans){
			ans=temp;
		}
	}
	printf("%d",ans);
	return 0;
} 
