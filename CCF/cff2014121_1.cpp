#include<bits/stdc++.h>
using namespace std;
int a[1003]={0};

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
		printf("%d ",a[x]);
	} 
	return 0;
} 
