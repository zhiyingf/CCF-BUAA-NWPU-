/*
	Name: 
	Copyright: 
	Author: 
	Date: 15/08/19 21:33
	Description: 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a; 
	char ch;
	int x;
	cin>>a;
	x=(a[0]-'0')*1+(a[2]-'0')*2+(a[3]-'0')*3+(a[4]-'0')*4+(a[6]-'0')*5+(a[7]-'0')*6+(a[8]-'0')*7+(a[9]-'0')*8+(a[10]-'0')*9;
	x%=11;
	if(x<10){
		ch=x+'0';
		}else{
			ch='X';
		}
	if(ch==a[a.size()-1]){
		cout<<"Right";
	}else{
		cout<<a.substr(0,12)+ch;
	}
	
	
	return 0;
}
