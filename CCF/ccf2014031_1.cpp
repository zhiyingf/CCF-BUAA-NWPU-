#include<bits/stdc++.h>
using namespace std;
int a[502]={0};
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x<0){
			if(a[-x]==0)
			a[-x]=-1;
			else if(a[-x]==1){
				ans++;
			}
		}else if(x>0){
			if(a[x]==0)a[x]=1;
			else if(a[x]==-1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
