#include<iostream>
#include<string>
#include<list>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int a=1,sum=0,i=0,temp=0,cou=0;
	while(a!=0){		
		scanf("%d",&a);
		i++;
		if(a==1){
			sum+=1;
			cou=0;
		}else if(a==2){
			cou++;
			sum+=2*cou;
		}else break;
	}
	printf("%d",sum);
	return 0;
}
