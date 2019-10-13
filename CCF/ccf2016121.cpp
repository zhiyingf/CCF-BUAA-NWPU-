#include<bits/stdc++.h>
using namespace std;
int a[1003];
int b[1003];

int main(){
	int n,num=0;
	scanf("%d",&n);
	fill(b,b+1003,0);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(!b[x]){
			b[x]++;
			a[num++]=x;
		}else {
			b[x]++;
		}
	}
	sort(a,a+num);
	int pre=0,ans;
	bool flag=false;
	for(int i=0;i<num;i++){
		if(2*pre+b[a[i]]==n){
			flag=true;
			ans=a[i];
			break;
		}
		pre+=b[a[i]];
	}
	
	if(flag)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
	
} 
