#include<bits/stdc++.h> 
using namespace std;
struct node{
	int a;
	int r;
}n1[10004];
int cmp(const node x,const node y){
	return x.a<y.a;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>n1[i].a;
		n1[i].r=i;
	}
	sort(n1,n1+n,cmp);
	for(int i=0;i<n;i++){
		cout<<n1[i].a<<" ";
	}cout<<endl;
	cout<<n/2<<endl;
	if(n%2==1){
		cout<<n1[n/2].a<<endl;
		cout<<n1[n/2].r+1<<endl;
	}else{
		cout<<n1[n/2-1].a<<" "<<n1[n/2].a<<endl;
		cout<<n1[n/2-1].r+1<<" "<<n1[n/2].r+1<<endl; 
	}
	return 0; 
}
