#include<bits/stdc++.h>
using namespace std;
int ab[1003];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&ab[i]);
	}
	if(n==2)printf("%d %d",(ab[0]+ab[1])/2,(ab[0]+ab[1])/2);
	else{
		printf("%d ",(ab[0]+ab[1])/2);
		for(int k=1;k<n-1;k++){
			printf("%d ",(ab[k-1]+ab[k]+ab[k+1])/3);
		}
		printf("%d",(ab[n-2]+ab[n-1])/2);
	}
	return 0;
}
