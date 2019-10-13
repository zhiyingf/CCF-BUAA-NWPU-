#include<iostream>
#include<string>
#include<list>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
map<string,int>mp;

struct info{
	int n=0;
	int a[102];
}ii[102];
int aa[11];

struct input{
	int n=0;
	string str1="";
	string str2="";
};

input change(string &str){
	input inp;
	for(int i=0;i<str.size();i++){
		if(isalpha(str[i])){
			//inp.str1=str.substr(i,str.size());
			string s="";
			for(int j=0;j<str.size();j++){
			s+=tolower(str[j]);
			inp.str1=s;
		}
			break;
		}
		if(str[i]-'.'==0){
			inp.n++;
			i+=2;
		}else if(isalpha(str[i])){
			inp.str1+=tolower(str[i++]);
		}else if(str[i]-' '==0){
			inp.str2=str.substr(i+1,str.size());
			string s="";
			for(int j=0;j<inp.str2.size();j++)s+=tolower(inp.str2[j]);
			inp.str2=s;
			break;
		}
	}
	return inp;
}
int main(){
	int n,m,k=0;
	string str;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str;
		input inp=change(str);
		if(mp.count(inp.str1)==0){
			mp[inp.str1]=k++;
		}
		ii[mp[inp.str1]].a[ii[mp[inp.str1]].n]=i;
		ii[mp[inp.str1]].n++;
		/*string s="";
		for(int j=0;j<str.size();j++){
			s+=tolower(str[j]);
		}
		if(mp.count(s)==0){
			mp[s]=k++;
		}
		ii[mp[s]].a[ii[mp[s]].n]=i;
		ii[mp[s]].n++;*/
	} 
	for(int i=0;i<m;i++){
		cin>>str;
		string s="";
		for(int j=0;j<str.size();j++){
			s+=tolower(str[j]);
		}
		str=s;
		if(mp.count(str)){
			aa[i]=mp[str];
		}else aa[i]=-1;
	}
	for(int i=0;i<m;i++){
		if(aa[i]==-1){
			cout<<"0"<<endl;
		}else{
			//cout<<"***"<<aa[i]<<endl;
			cout<<ii[aa[i]].n<<" ";
			for(int j=0;j<ii[aa[i]].n;j++){
				cout<<ii[aa[i]].a[j]+1<<" ";
			}
			cout<<endl;
		}
	}
}
