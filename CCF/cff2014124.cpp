#include<bits/stdc++.h>
using namespace std;
struct node{
	bool kind;
	float money;
	int number;
	friend bool operator < (const node &no1,const node &no2){
		return no1.money<no2.money;
	}
};
vector<node>ve;
int main(){
	int i=0;
	string str;
	float x;
	int y;
	while(cin>>str){
		node no;
		if(str=="buy"){
			no.kind=true;
		    cin>>x>>y;
		}else if(str=="sell"){
			no.kind=false;
			cin>>x>>y;
		}
		no.money=x;
		no.number=y;
		ve.push_back(no);
	}
	return 0;
}
