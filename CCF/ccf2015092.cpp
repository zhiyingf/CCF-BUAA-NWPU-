#include<bits/stdc++.h>
using namespace std;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isyear(int x){
	if((x%4==0&&x%100!=0)||x%400==0)return true;
	else return false;
}
int main(){
	int year,day;
	scanf("%d%d",&year,&day);
	if(isyear(year))month[1]=29;
	
		int ansmon=1,ansday=0;
		for(int i=0;i<12;i++){
			if(day>month[i]){
				day-=month[i];
				ansmon++;
			}else{
				ansday=day;
				break;
			}
		}
		printf("%d\n%d\n",ansmon,ansday);
		return 0;
	
}
