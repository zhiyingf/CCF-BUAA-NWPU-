#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;//����ʱҪ�ûس����������룬����Ҫ���ǻ��������ڵĻس��� 
	getchar();
	while(n--){
		string str;
		getline(cin,str);
		bool flag=true;
		int size=str.size();
		for(int i=0;i<size/2;i++){
			if(str[i]!=str[size-i-1])flag=false;
		}
		if(flag)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
} 
