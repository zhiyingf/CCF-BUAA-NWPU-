/**
����˼·��
1����һ���˵Ľ軹��������ͳ���ǣ����Ƕ���������ʱ��㿼�ǣ�����ʱ��Ľ��� һ��һ�����л�ķ�����
2��ÿ��ʱ���Ĳ�����򻹣���ʱ����С������������ִ��ÿ������--��mp��
3��map<int,int> map[i]=j��ʾλ��i��Կ�׺�Ϊj��0��ʾ�գ���̬��a[i]=i;
���ⲽ�裺
1�����롢����ʱ���ṹ�壩 
2���������������δ���
x.lent==0;map<int,int>::iterator it= mp.find(x.sign);it->second=0;
x.lent==1;it=mp.find(x,sign);λ��y=it->first;����1->y,��Ϊ0ʹ֮Ϊx.sign; 
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
struct node{
	int time,sign,lent;//ʱ��㣬Կ�׺ţ���=0����=1�� 
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
		int w,s,c;//Կ�׺ţ���ʼ��ʱ�� 
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
		if(lent==0){//�� 
			//it= mp.find(sign);????????????????Ϊʲô�����ԣ�ƫҪ����ʹ��ѭ�����ң������������������� 
			//it->second=0;
			//mp[it->first]=0;
			for(it=mp.begin();it!=mp.end();it++){
				if(it->second==sign){
					it->second=0;
					//printf("lent=0**%d %d**\n",it->first,it->second);
					break;
				}
			}
		
		}else{//�� 
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
