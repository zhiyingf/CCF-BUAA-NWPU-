#include<bits/stdc++.h>
using namespace std;
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
int isleap(int year){
	if((year%4==0&&year%100!=0)||year%400==0)return 366;
	else return 365;
}
int main(){
	int a,b,c,y1,y2;
	int sum=0;
	scanf("%d%d%d%d%d",&a,&b,&c,&y1,&y2);
	for(int i=1850;i<y1;i++){
		sum+=isleap(i);
	}
	int cnaw=(2+sum)%7;//1.1
	
	int you=0;
	bool none;
	
	for(int i=y1;i<=y2;i++){
		if(cnaw==0)cnaw=7;
		none=false;
		int leap;
		you=1;
		if(isleap(i)==365)leap=0;
		else leap=1;
		int mon=0;
		if(a!=1){
			for(int j=1;j<a;j++)mon+=month[j][leap];
		}
		int anaw=(cnaw+mon)%7;//a.1
		if(anaw==0)anaw=7;
		
		//printf("cnaw=%d\n",cnaw); 
		//printf("anaw=%d\n",anaw);
		
		if(b==1){
			if((c-anaw)<0)none=true;
			you+=c-anaw;
		}else{
			you+=7-anaw;
			for(int u=2;u<b;u++)you+=7;
			you+=c;
		}
		if(you>=month[a][leap])none=true;
		if(none)printf("none\n");
		else printf("%04d/%02d/%02d\n",i,a,you);
		
		cnaw=(cnaw+isleap(i))%7;		
	}
	
	
	return 0;
}
