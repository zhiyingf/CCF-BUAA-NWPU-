/*������ģ�⣬��Ҫ������ǣ�1<=n<=100,1<=m<=10,��ʱ����ķ����������㣬��һ��������ϸ�����ɸ�С���⣬ 
Ȼ������������������������ģ������Ľ����Χ����ʱ��ѧ�ᴿ����ģ�⡣ 
�ջ��ַ��������룺getchar();�������ջس���getline(cin,string,'/') ;cin.getline(array,size,'/')����һ�У��ɺ��ո�
gets();��'/0'��
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

string mystrlwr(string input){//���ַ���ȫ��ΪСд�ַ��� 
	string s="";
	for(int i=0;i<input.size();i++){
	s+=tolower(input[i]);	
	}
	return s;
}

void split(char *s,vector<string>&v){// �Կո���зָ��ַ���s�������ָ���������v�� 
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
			string temp=demand.back();/**end() ��������һ��ָ��ǰvectorĩβԪ�ص���һλ�õĵ�����.
			Ҫ����ĩβԪ��,��Ҫ�Ƚ��˵�������1��back() �������ص�ǰvector��ĩһ��Ԫ�ص����á� */
			for(int j=0;j<n;j++){
				if(temp==A[j].lable||temp==A[j].id){//�����ҵ��������һ��Ԫ�ص�λ������ӦԪ��--�ټ�������Ԫ���Ƿ����� 
					int sum=demand.size()-2;
					for(int k=j-1;k>=0&&A[k].level<=A[j].level;k--){//��temp������ 
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
