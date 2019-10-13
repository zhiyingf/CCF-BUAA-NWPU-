#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[100],p[100];
bool cmp1(const int i,const int j){
	return a[i]<a[j];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
	}
	sort(p,p+n,cmp1);
	for(int i=0;i<n;i++){
		if(i==0)printf("%d",p[i]+1);
		else printf(" %d",p[i]+1);
	}
    return 0;
}
