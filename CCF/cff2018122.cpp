#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int r,y,g,n,x,yy;
	scanf("%d%d%d%d",&r,&y,&g,&n);
	int ryg=r+y+g;//红黄绿为一个循环 
	
	long long sum=0;//唔，这里如果用int的话，错误，只能得60分。 
	int temp=0;
	
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&yy);
		switch(x){
			case 0:
				sum+=yy;
				break;
			case 1:			
				if(sum>yy){
					temp=(sum-yy)%ryg;
					if(temp<g){
						continue;
					}else{
						temp-=g;
						if(temp<y){
							sum=sum-temp+r+y;
						}
						else{
							temp-=y;
							sum=sum-temp+r;
						}
					}
				}
				else{
					sum+=yy;				
				}				
				break;
			case 2:
				if(sum>yy){
					temp=(sum-yy)%ryg;
					if(temp<r){
						sum=sum-temp+r;
					}else{
						temp-=r;
						if(temp<g){
							continue;
						}else{
							temp-=g;
							sum=sum-temp+r+y;
						}
					}				
				}
				else{
					sum=sum+yy+r;
				}
				break;
			case 3:
				if(sum>yy){
					temp=(sum-yy)%ryg;
					if(temp<y){
						sum=sum-temp+r+y;
					}else{
						temp-=y;
						if(temp<r){
							sum=sum-temp+r;
						}						
					}				
				}				
				break;
			default:
			break;				
		}
	}
	printf("%lld",sum);
	return 0;
}
