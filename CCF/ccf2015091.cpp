#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x,last_x,ans=1;
	cin>>last_x;
	for(int i=1;i<n;i++){
		cin>>x;
		if(last_x!=x){
			ans++;
			last_x=x;
		}
		 
	}
	cout<<ans;
	return 0;
}
