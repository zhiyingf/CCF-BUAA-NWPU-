#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;//mp[i]=j位置i为学生j 
int main(){
	int n,m,p,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		mp[i]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&p,&q);
		int pos;
		//map<int,int>::iterator it=mp.find(p);
		/*for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			if(it->second==p){
				pos=it->first;
				break;
			}
		}*/
		for(int i=1;i<=n;i++){
			if(mp[i]==p){
				pos=i;
				break;
			}
		}
		int ii;
		if(q>0){
			for(ii=pos;ii<pos+q;ii++){
				mp[ii]=mp[ii+1];
			}
			mp[ii]=p;
		}else if(q<0){
			for(ii=pos;ii>pos-abs(q);ii--){
				mp[ii]=mp[ii-1];
			}
			mp[ii]=p;
		}
		/*printf("\n");
		for(int i=1;i<=n;i++){
		printf("%d ",mp[i]);
	    }
	    printf("\n");*/
	}
	for(int i=1;i<=n;i++){
		printf("%d ",mp[i]);
	}
	return 0;
}
