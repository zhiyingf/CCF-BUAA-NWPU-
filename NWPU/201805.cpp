#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--){
		string str,str1;
		getline(cin,str);
		for(int i=str.size()-1;i>=0;i--){
			str1+=str[i];
		}
		cout<<str1<<endl;//endl��ˢ�·��ţ���Ҫ��getchar()���ջس���������û�лس������� 
	}
	return 0;
}
