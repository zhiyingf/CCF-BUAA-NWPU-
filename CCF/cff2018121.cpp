#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int r,y,g,n,x,yy;
	scanf("%d%d%d%d",&r,&y,&g,&n);
	
	int sum=0;
	
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&yy);
		switch(x){
			case 0:
				sum+=yy;
				break;
			case 1:
				sum+=yy;
				break;
			case 2:
				sum=sum+yy+r;
				break;
			case 3:
				break;
			default:
				printf("ÊäÈë´íÎó\n");
		}
	}
	printf("%d",sum);
	return 0;
}
