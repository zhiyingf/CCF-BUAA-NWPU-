#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	getchar();
	for(int k=0;k<n;k++){
		string str;
		stack<int> st1;
		//stack<char>st2;
		getline(cin,str);
		for(int i=0;i<7;i++){
			if('1'<=str[i]&&str[i]<='9')st1.push(str[i]-'0');
			else if(str[i]=='+'){
				i++;
				//st2.push('+');
				st1.push(str[i]-'0');
			}
			else if(str[i]=='-'){
				i++;
				st1.push('0'-str[i]);
				//st2.push('+');
			}
			else if(str[i]=='x'){
				i++;
				int temp=st1.top();
				st1.pop();
				temp*=str[i]-'0';
				st1.push(temp);
			}
			else if(str[i]=='/'){
				i++;
				int temp=st1.top();
				st1.pop();
				temp/=str[i]-'0';
				st1.push(temp);
			}
		}
		int ans=0;
		while(!st1.empty()){
			ans+=st1.top();
			st1.pop();
		}
		if(ans==24)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
