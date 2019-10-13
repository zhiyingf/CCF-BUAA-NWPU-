#include<bits/stdc++.h>
using namespace std;
int ab[1003];
int main(){
	long long count=0;
	int n,k;
	scanf("%d%d",&n,&k);
	int ncopy=n,i=-1;
	for(int kk=0;kk<n;kk++){
		ab[kk]=kk+1;
	}
	while(ncopy>1){
		count++;
		i=(i+1)%n;
		while(!ab[i]){
			i=(i+1)%n;
		}
		if(count%10==k||count%k==0){
			ab[i]=0;
			ncopy--;
		}
	}
	for(int kk=0;kk<n;kk++){
		if(ab[kk]){
			printf("%d",ab[kk]);
			break;
		}
	}
	return 0;
}
