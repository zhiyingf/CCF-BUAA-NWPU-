#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int ans=x;
		while(--x){
			ans*=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
