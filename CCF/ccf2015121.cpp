#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int ans=0;
	for(int i=0;i<a.size();i++){
		ans+=a[i]-'0';
	}
	cout<<ans;
	return 0;
}
