#include<bits/stdc++.h>
using namespace std;
int seat[25];
int main(){
	int n,x;
	scanf("%d",&n);
	fill(seat,seat+25,0);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		int flag=false;
		for(int k=0;k<20;k++){
			if(seat[k]+x<=5){
				flag=true;
				for(int u=seat[k]+1;u<seat[k]+x;u++){
					printf("%d ",u+k*5);
				}
				printf("%d\n",x+seat[k]+k*5);
				seat[k]+=x;
				
				break;
			}
		}
		if(!flag){
			for(int k=0;k<20;k++){
				for(int u=seat[k]+1;u<=5;u++){
					x--;
					seat[k]=u;
					if(x)printf("%d ",u+5*k);
					else{
						printf("%d\n",u+5*k);
						break;
					}
				} 
				if(!x)break;
			}
		}
	}
	
	return 0;
}
