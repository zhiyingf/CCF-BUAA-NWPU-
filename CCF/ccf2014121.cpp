#include<bits/stdc++.h>
using namespace std;
int a[1003]={0};
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		a[x]++;
		cout<<a[x]<<" ";
	}
	return 0;
}
