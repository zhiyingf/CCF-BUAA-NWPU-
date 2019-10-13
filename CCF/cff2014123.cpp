#include<bits/stdc++.h>
using namespace std;
struct node{
	float p;//p 出价 
	long long s;//s 股数 
	friend bool operator < (const node &no1,const node &no2){
		return no1.p<no2.p;
	}
};
map<int,pair<bool,int> >mp;//mp<i,<true,j> >第i次，bool=true为buy，j为 
vector<node>before,buy,sell;//vector:用于排序 

int main(){
	node no;
	string a;
	int i=0,by=0,se=0;
	while(cin>>a){
		if(a[0]=='b'){
			cin>>no.p>>no.s;
			buy.push_back(no);
			mp[i++]=make_pair(true,by++);
		}
		else if(a[0]=='s'){
			cin>>no.p>>no.s;
			sell.push_back(no);
			mp[i++]=make_pair(false,se++);
		}
		else if(a[0]='c'){
			i++;
			int x;
			cin>>x;
			pair<bool,int> p=mp[x-1];
			if(p.first){buy[p.second].p=0;buy[p.second].s=0;}//buy.erase(buy.begin()+p.second);
			else {sell[p.second].p=0;sell[p.second].s=0;}//sell.erase(sell.begin()+p.second);
			//printf("cell %d\n",x);
		}else break;
	}
	
	sort(buy.begin(),buy.end());
	sort(sell.begin(),sell.end());
	for(int i=1;i<sell.size();i++){
		sell[i].s+=sell[i-1].s; 
		if(sell[i].p==sell[i-1].p)sell.erase(sell.begin()+i-1);
		//printf("sell %.2f %d\n",sell[i].p,sell[i].s);
	}
	for(int i=buy.size()-2;i>=0;i--){
		buy[i].s+=buy[i+1].s; 
		if(buy[i].p==buy[i+1].p)buy.erase(buy.begin()+i+1);
		//printf("buy %.2f %d\n",buy[i].p,buy[i].s);
	}
	//vector<node>::iterator it;
	long long ans1=0;
	float ans2;
	int buy1=0,sell1=0;
	while(buy1<buy.size()&&sell1<sell.size()){
		if(buy[buy1].p==sell[sell1].p){
			int temp=min(buy[buy1].s,sell[sell1].s);
			if(ans1<temp){
				ans1=temp;
			    ans2=buy[buy1].p;
			}
			buy1++;sell1++;
		}else if(buy[buy1].p<sell[sell1].p){
			int temp=min(buy[buy1].s,sell[sell1].s);
			if(ans1<temp){
				ans1=temp;
				ans2=sell[sell1].p;
			}
			buy1++;
		}else{
			int temp=min(buy[buy1].s,sell[sell1].s);
			if(ans1<temp){
				ans1=temp;
				ans2=sell[sell1].p;
			}
			sell1++;
		}
	}
	printf("%.2f %lld",ans2,ans1);
	return 0;
} 
