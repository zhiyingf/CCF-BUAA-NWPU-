#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	int ans=x;
	if(x>y){
		while(--x&&--y){
			ans*=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
