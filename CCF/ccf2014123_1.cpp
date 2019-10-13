//学会抓住问题关键，不能眉毛胡子一把抓 
#include<bits/stdc++.h>
using namespace std;
struct node{
	double p;
	long long s;
	int id;
};
vector<node>buy,sell;
set<double>st;
bool flag[5003];
int main(){
	fill(flag,flag+5003,true);
	string str;
	node no;
	int id=1;
	while(cin>>str){
		if(str=="buy"){
			no.id=id++;
			cin>>no.p>>no.s;
			buy.push_back(no);
		}else if(str=="sell"){
			no.id=id++;
			cin>>no.p>>no.s;
			sell.push_back(no);
		}else if(str=="cancel"){
			int x;
			cin>>x;
			flag[x]=false;
			id++;
		}
	}
	for(int i=0;i<buy.size();i++){
		if(flag[buy[i].id])st.insert(buy[i].p);
	}
	for(int i=0;i<sell.size();i++){
		if(flag[sell[i].id])st.insert(sell[i].p);
	}
	double ans1=0;
	long long ans2=0;
	for(set<double>::iterator it=st.begin();it!=st.end();it++){
		double price=*it;
		long long temp1=0,temp2=0;
		for(int i=0;i<buy.size();i++){
			if(flag[buy[i].id]&&price<=buy[i].p){
				temp1+=buy[i].s; 
			}
		}
		for(int i=0;i<sell.size();i++){
			if(flag[sell[i].id]&&price>=sell[i].p){
				temp2+=sell[i].s;
			}
		}
		temp1=min(temp1,temp2);
		if(ans2<=temp1){
			ans1=price;
			ans2=temp1;
		}
	}
	printf("%.2f %lld",ans1,ans2);
	return 0;
}
