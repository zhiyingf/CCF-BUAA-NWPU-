#include<bits/stdc++.h>
using namespace std;
struct par{
	int a,b;
}part[10004]; 
bool cmp(par p1,par p2){
	return p1.a<p2.a;//p1ÅÅÔÚp2Ç° 
}
int main(){
	int n,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&part[i].a);
		part[i].b=i;
	}
	sort(part,part+n,cmp);
	ans=n/2;
	if(n%2==1){
		printf("%d %d",part[ans].a,part[ans].b+1);
	}else printf("%d %d\n%d %d",part[ans-1].a,part[ans-1].b+1,part[ans].a,part[ans].b+1);
	return 0;
}
