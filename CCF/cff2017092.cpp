/**
解题思路：
1、将一个人的借还操作不笼统考虑，而是独立成两个时间点考虑，按照时间的进行 一个一个进行活动的发生；
2、每个时间点的操作借或还，将时间点从小到大排序，依次执行每个操作--变mp；
3、map<int,int> map[i]=j表示位置i的钥匙号为j，0表示空，初态有a[i]=i;
解题步骤：
1、输入、排序（时间点结构体） 
2、对排序数组依次处理：
x.lent==0;map<int,int>::iterator it= mp.find(x.sign);it->second=0;
x.lent==1;it=mp.find(x,sign);位置y=it->first;遍历1->y,有为0使之为x.sign; 
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
struct node{
	int time,sign,lent;//时间点，钥匙号，借=0，还=1； 
};
bool cmp(const node &no1,const node &no2){
	if(no1.time==no2.time){
		if(no1.lent==no2.lent)return no1.sign<no2.sign;
		else return no1.lent>no2.lent;
	}else return no1.time<no2.time;
}
vector<node> ve;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		mp[i]=i;
	}
	for(int i=0;i<k;i++){
		int w,s,c;//钥匙号，开始，时长 
		scanf("%d%d%d",&w,&s,&c);
		node no1,no2;
		no1.lent=0;no1.sign=w;no1.time=s;
		no2.lent=1;no2.sign=w;no2.time=s+c;
		ve.push_back(no1);
		ve.push_back(no2);
	}
	sort(ve.begin(),ve.end(),cmp);
	
	while(!ve.empty()){
		node no=ve.front();
		ve.erase(ve.begin());
		int lent=no.lent;
		int time=no.time;
		int sign=no.sign;
		//printf("\n*%d %d %d*\n",lent,sign,time);
		map<int,int>::iterator it;
		if(lent==0){//借 
			//it= mp.find(sign);????????????????为什么不可以，偏要让我使用循环来找？？？？？？？？？？ 
			//it->second=0;
			//mp[it->first]=0;
			for(it=mp.begin();it!=mp.end();it++){
				if(it->second==sign){
					it->second=0;
					//printf("lent=0**%d %d**\n",it->first,it->second);
					break;
				}
			}
		
		}else{//还 
			for(it=mp.begin();it!=mp.end();it++){
				if(it->second==0){
					it->second=sign;
					//printf("lent=1**%d %d**\n",it->first,it->second);
					break;
				}
			}
		}
		//for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		//printf("%d ",it->second);
	    //}
	    //printf("\n"); 
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		printf("%d ",it->second);
	}
	return 0;
}
