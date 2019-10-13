#include<bits/stdc++.h>
using namespace std;
int ab[1003];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		ab[i]=i;
	}
	for(int u=0;u<k;u++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;i++){
			if(ab[i]==a){
				if(b>0){//向后移 
					int j=i+1;
					for(;j<=i+b;j++){
						ab[j-1]=ab[j];
					}
				}else if(b<0){//向前移 
					int j=i-1;
					for(;j>=i+b;j--){
						ab[j+1]=ab[j];
					}
				}
				ab[i+b]=a;
				break; 
			}
		}
	}
	printf("%d",ab[1]);
	for(int i=2;i<=n;i++){
		printf(" %d",ab[i]);
	}
	printf("\n");
	return 0;
}
