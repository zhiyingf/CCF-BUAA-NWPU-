#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
typedef pair<int,int> P;
vector<P > ve;
bool cmp(const P x,const P y){
	if(x.first==y.first){
		return x.second<y.second;
	}else return x.first>y.first;
}
int main(){
	int n;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		mp[x]++;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		ve.push_back(make_pair(it->second,it->first));
	}
	sort(ve.begin(),ve.end(),cmp);
	printf("%d",ve.front().second);
	return 0;
} 
