#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,anew;
	cin>>a>>b>>c;
	anew=a;
	int i=0,j=0,num=0;
	for(;i<a.size();i++){
		for(;j<b.size();j++){
			if(a[i+j]!=b[j]){
				j=0;
				break;
			}
		}
		if(j==b.size()&&a[i+j-1]==b[j-1]){			
		    anew.replace(num+i,j,c);
		    if(b.size()<=c.size())num+=c.size()-b.size();
		    else num-=b.size()-c.size();
		}
	}
	
	cout<<anew<<endl;
	
	return 0;
} 
