#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int min,max;
	double mid;
	if(a[n-1]>a[0]){
		min=a[0];max=a[n-1];
	}
	else{
		min=a[n-1];max=a[0];
	}
	if(n%2==1){//n=1,n/2=0Тњзу n=2 
		mid=a[n/2];
		printf("%d %.0f %d",max,mid,min);
	}else {
		if((a[n/2]+a[(n/2)-1])%2==0){
			mid=(a[n/2]+a[(n/2)-1])/2;
		    printf("%d %.0f %d",max,mid,min);
		}else{
			mid=(a[n/2]+a[(n/2)-1])*1.0/2;
		    printf("%d %.1f %d",max,mid,min);
		}
	}
	return 0;
}
