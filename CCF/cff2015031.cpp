#include<bits/stdc++.h>
using namespace std;
int a[1003][1003];
int b[1003][1003];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			b[m-1-j][i]=a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
