/*纯暴力模拟，你要清楚的是：1<=n<=100,1<=m<=10,有时候最笨的方法或许最简便，把一个大问题细化若干个小问题， 
然后再逐个解决。当问题的输入规模（问题的解决范围不大时）学会纯暴力模拟。 
收获：字符串的输入：getchar();用于吸收回车；getline(cin,string,'/') ;cin.getline(array,size,'/')输入一行，可含空格
gets();含'/0'；
isdigit(char);isalpha(char);tolower(char);toupper(char);char *p=strtok(char array," ");
string.substr(cnt,len);
*/ 
#include<map>
#include<iostream>
#include<string>
#include<cstdio>
#include<vector> 
#include<ctype.h>
#include<cstring>
using namespace std;
vector<string> demand;
//map<string,int> an,query;
struct NODE{
	int level=0;
	string lable="",id="";
}A[102];

string mystrlwr(string input){//将字符串全变为小写字符串 
	string s="";
	for(int i=0;i<input.size();i++){
	s+=tolower(input[i]);	
	}
	return s;
}

void split(char *s,vector<string>&v){// 以空格进行分割字符串s，并将分割结果保存在v中 
	v.clear();
	char *p=strtok(s," ");
	while(p){
		v.push_back(p);
		p=strtok(NULL," ");
	}
	for(int j=0;j<v.size();j++){
				if(v[j][0]!='#'){
					v[j]=mystrlwr(v[j]);
				}
			}
}

int transport(string input,int position){
	int cnt=0,len=0,pos=0;
	for(int i=0;i<input.size()&&input[i]=='.';i++,cnt++);
	for(int i=cnt;i<input.size();i++,len++){
		if(input[i]==' '&&i+1<input.size()&&input[i+1]=='#'){
			pos=i+1;
			break;
		}
	}
	A[position].level=cnt;
	A[position].lable=mystrlwr(input.substr(cnt,len));
	if(pos>0)
	A[position].id=input.substr(pos);
	return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;i++){
		string input;
		getline(cin,input);
		transport(input,i);
	}
	for(int i=0;i<m;i++){
		char a[90];
		cin.getline(a,90);
		//gets(a);
		split(a,demand);
		vector<int>ans;
		if(demand.size()==1){
			string temp=demand[0];
			for(int j=0;j<n;j++){
				if(temp==A[j].lable||temp==A[j].id){
					ans.push_back(j);
				}
			}
		}else{
			string temp=demand.back();/**end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.
			要访问末尾元素,需要先将此迭代器减1。back() 函数返回当前vector最末一个元素的引用。 */
			for(int j=0;j<n;j++){
				if(temp==A[j].lable||temp==A[j].id){//首先找到满足最后一个元素的位置与相应元素--再检验祖先元素是否满足 
					int sum=demand.size()-2;
					for(int k=j-1;k>=0&&A[k].level<=A[j].level;k--){//找temp的祖先 
						if(A[k].level==A[j].level){
							continue;
						}
						if(A[k].lable==demand[sum]||demand[sum]==A[k].id){
							if(sum==0){
								ans.push_back(j);
								break;
							}
							sum--;
						}					
					}
				}	 
			}				
		}
		printf("%d",ans.size());
		for(int i=0;i<ans.size();i++)
		printf(" %d",ans[i]+1);
		printf("\n");
	}
	return 0;
} 
