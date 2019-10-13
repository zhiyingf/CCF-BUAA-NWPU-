#include<bits/stdc++.h>
using namespace std;
int a[10004];
int main(){
	int m,n;
	cin>>m>>n;
	while(m--){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
