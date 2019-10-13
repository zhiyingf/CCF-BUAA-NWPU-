#include<bits/stdc++.h>
using namespace std;
int a[1003];
typedef pair<int,int> P;
vector<P> ve;
bool cmp(const P x,const P y){
	if(x.first==y.first)return x.second<y.second;
	else return x.first>y.first;
}
int main(){
	int n;
	scanf("%d",&n);
	fill(a,a+1003,0);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	//sort(a,a+1003,cmp);
	for(int i=0;i<1003;i++){
		if(a[i])ve.push_back(make_pair(a[i],i));
	}
	sort(ve.begin(),ve.end(),cmp);
	for(vector<P>::iterator it=ve.begin();it!=ve.end();it++){
		printf("%d %d\n",it->second,it->first);
	}
	return 0;
}
