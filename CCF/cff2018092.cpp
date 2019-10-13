#include<iostream>
#include<string>
#include<list>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int a[2003];
int b[2003];
int main(){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	int j=1;
	bool flag=true;
	for(int i=1;i<=n;i++){
		int c,d;
		scanf("%d%d",&c,&d);	
		if(d<=a[j]&&flag)continue;				
		while(c>=b[j]&&j<n)j++;
		while(d>=b[j]&&c<b[j]){
			if(c<=a[j]){
				sum+=b[j]-a[j];							
			}else{
			sum+=b[j]-c;					
		    }
		    j++;
	    }
		if(d<b[j]&&d>a[j]){
			if(c<=a[j]){
				sum+=d-a[j];								
			}else{
				sum+=d-c;				
			}
			continue;
			//j++; 错误 
		}
		if(j==n&&d>=a[n])flag=false;//可有可无		
	}
	printf("%d",sum);
	return 0;
}
