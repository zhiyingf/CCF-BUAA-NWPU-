#include<bits/stdc++.h>
using namespace std;
int f[1003];
int main(){
	int n,ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	for(int i=1;i<n-1;i++){
		if(f[i]>f[i-1]&&f[i]>f[i+1])ans++;
		else if(f[i]<f[i-1]&&f[i]<f[i+1])ans++;
	}
	cout<<ans;
	return 0;
}
