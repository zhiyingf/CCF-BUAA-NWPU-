#include<bits/stdc++.h>
using namespace std;
bool aa[10004];
int main(){
	int n;
	cin>>n;
	fill(aa,aa+10004,false);
	while(n--){
		int x;
		cin>>x;
		aa[x]=true;
	}
	int ans=0;
	for(int i=1;i<10004;i++){
		if(aa[i]&&aa[i-1])ans++;
	}
	cout<<ans;
	return 0;
}
