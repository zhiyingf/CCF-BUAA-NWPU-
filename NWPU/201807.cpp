#include<bits/stdc++.h>
using namespace std;
char ch[2][4]={{'{','[','('},{'}',']',')'}};
int main(){
	int n;
	cin>>n;
	getchar();
	while(n--){
		string str;
		getline(cin,str);
		int s=str.size();
		stack<char>st;
		bool flag=true;
		for(int i=0;i<s;i++){
			if(str[i]==ch[0][0]||str[i]==ch[0][1]||str[i]==ch[0][2]){
				st.push(str[i]);
			}else if(str[i]==ch[1][0]){
				if(st.top()==ch[0][0])st.pop();
				else{
					flag=false;break;
				}
			}else if(str[i]==ch[1][1]){
				if(st.top()==ch[0][1])st.pop();
				else{
					flag=false;break;
				}
			}else if(str[i]==ch[1][2]){
				if(st.top()==ch[0][2])st.pop();
				else{
					flag=false;break;
				}
			}else continue;
		}
		if(!st.empty())flag=false;
		if(flag)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
