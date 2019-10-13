#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int min,max,mid1,mid2;
	mid1=mid2=0;
	if(n%2==0){
		mid1=(1+n)/2;
		mid2=mid1+1;
	}else mid1=(1+n)/2;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i==1)min=x;
		else if(i==n)max=x;
		else if(i==mid1)mid1=x;
		else if(i==mid2)mid2=x;
	}
	if(min>max){
		int temp=min;
		min=max;
		max=temp;
	}
	if((mid1+mid2)%2==0){
		if(n%2==1)printf("%d %d %d",max,mid1,min);
		else printf("%d %d %d",max,(mid1+mid2)/2,min);
	}
	else {
		printf("%d %.1f %d",max,(mid1+mid2)*1.0/2,min);
	}
}
