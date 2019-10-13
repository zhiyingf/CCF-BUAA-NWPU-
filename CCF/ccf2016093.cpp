#include<bits/stdc++.h>
using namespace std;
struct atter{
	int att=0,hea=0;
};
struct game{
	int hero=30;
	atter at[8];
}ga[2];
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char str[100]="";
	int flag=0;
	while(n--){
		cin.getline(str,100);
		if(str[0]=='e'){
			flag=(flag+1)%2;
		}else if(str[0]=='s'){
			char str1[100];
			int a,b,c;
			sscanf(str,"%s %d %d %d",str1,&a,&b,&c);
			if(ga[flag].at[a].hea>0){
				for(int i=6;i>=a;i--){
					ga[flag].at[i+1]=ga[flag].at[i];
				}
			}
			ga[flag].at[a].att=b;
			ga[flag].at[a].hea=c;
		}else if(str[0]=='a'){
			char str1[100];
			int a,b;
			sscanf(str,"%s %d %d",str1,&a,&b);
			if(b>0){
				ga[flag].at[a].hea-=ga[(flag+1)%2].at[b].att;
				ga[(flag+1)%2].at[b].hea-=ga[flag].at[a].att;
				if(ga[flag].at[a].hea<=0){
					for(int j=a;j<7;j++){
						ga[flag].at[j]=ga[flag].at[j+1];
					}
				}
				if(ga[(flag+1)%2].at[b].hea<=0){
					for(int j=b;j<7;j++){
						ga[(flag+1)%2].at[j]=ga[(flag+1)%2].at[j+1];
					}
				}
			}else if(b==0){
				ga[(flag+1)%2].hero-=ga[flag].at[a].att;
			}
		}
	}
	
	if(ga[0].hero>0&&ga[1].hero>0){
		printf("0\n");
	}else if(ga[0].hero>0&&ga[1].hero<=0){
		printf("1\n");
	}else if(ga[1].hero>0&&ga[0].hero<=0){
		printf("-1\n");
	}
	for(int i=0;i<=1;i++){
		printf("%d\n",ga[i].hero);
		int ans1=0;
		for(int j=1;j<8;j++){
			if(ga[i].at[j].hea>0)ans1++;
		}
		printf("%d",ans1);
		for(int j=1;j<8;j++){
			if(ga[i].at[j].hea>0)printf(" %d",ga[i].at[j].hea);
		}
		if(i==0)printf("\n");
	}
	
	
	return 0;
} 
