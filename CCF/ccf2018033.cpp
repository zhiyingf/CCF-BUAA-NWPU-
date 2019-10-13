#include<bits/stdc++.h>
using namespace std;
struct node{
	string id;
	string pre;
	bool bol[10];
	int num;
}noe[102];

void change(string str,ii){
	int pos1,pos2,pos;
	pos1=str.find("/",1);
	if(pos1!=string::npos){
		noe[ii].pre=str.substr(1,pos1-1);
	}
	pos2=str.find(" ",pos1);
	if(pos2!=string::npos){
		noe[ii].id=str.substr(pos2+1);
	}
	string str1=str.substr(pos1+1,pos2-pos1-1);
	while(pos!=string::npos){
		    string st;
			pos1=str.find("/",pos);
			if(pos1!=string::npos)st=str.substr(pos,pos1-pos);
			if(st=="<int>")
			pos=pos1;
		}
}

int main(){
	int n,m;
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		change(str,i);
	}
	for(int j=0;j<m;j++){
		string str;
		cin>>str;
		
		int pos=1,pos1;
		node no;
		while(pos!=string::npos){
			pos1=str.find("/",pos);
			if(pos1!=string::npos)no.pre=str.substr(pos,pos1-pos);
			pos=pos1;
		}
		for(int i=0;i<n;i++){
			if(noe[i].pre==)
		}
	}
	return 0;
} 
