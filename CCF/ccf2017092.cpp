#include<bits/stdc++.h>
using namespace std;
int seat[1003];
struct point{
	int key,time;
	int type;//½è0£¬»¹1
	point(){}
	point(int _key,int _time,int _type){
		key=_key;
		time=_time;
		type=_type;
	}
};

vector<point>jh;

bool cmp(const point p1,const point p2){
	if(p1.time==p2.time){
		if(p1.type==p2.type){
			return p1.key<p2.key;
		}else{
			return p1.type>p2.type;
		}
	}else return p1.time<p2.time;
}

int main(){
	int n,k,a,b,c;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)seat[i]=i;
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&a,&b,&c);
		point p1(a,b,0);
		point p2(a,b+c,1);
		jh.push_back(p1);
		jh.push_back(p2);
	}
	sort(jh.begin(),jh.end(),cmp);
	for(int i=0;i<k*2;i++){
		point pp=jh[i];
		int key=pp.key;
		int time=pp.time;
		if(pp.type==0){//½è
			for(int u=1;u<=n;u++){
				if(seat[u]==key){
					seat[u]=0;
					break;
				}
			} 
		}else{//»¹ 
			for(int u=1;u<=n;u++){
				if(seat[u]==0){
					seat[u]=key;
					break;
				}
			}
		}
	}
	for(int i=1;i<n;i++)
	printf("%d ",seat[i]);
	printf("%d\n",seat[n]);
	return 0;
}
