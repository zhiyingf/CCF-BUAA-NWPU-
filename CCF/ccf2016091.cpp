#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,last_x,ans=0,x;
	cin>>n;
	cin>>last_x;
	for(int i=1;i<n;i++){
		cin>>x;
		if(ans<abs(last_x-x))ans=abs(last_x-x);
		last_x=x;
	}
	cout<<ans;
	return 0;
}
