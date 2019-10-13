#include<bits/stdc++.h>
using namespace std;
int ab[35][35],ans[35][35];
const int inf=1e8;

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&ab[i][j]);
			ans[i][j]=inf;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int nowi=i+1,nowj=j+1,now=ab[i][j];
			if(i-1<0||now!=ab[i-1][j]){//查列 
				int num=1;
				while(nowi<n&&now==ab[nowi][j])num++,nowi++;
				if(num>=3){
					//cout<<m<<"*"<<endl; 
					for(int v=i;v<i+num;v++){
						ans[v][j]=0;
					}
				}
			}
			if(j-1<0||now!=ab[i][j-1]){//查行 
				int num=1;
				while(nowj<m&&now==ab[i][nowj])num++,nowj++;
				if(num>=3){
					//cout<<m<<"*"<<endl; 
					for(int v=j;v<j+num;v++){
						ans[i][v]=0;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(ans[i][j]!=0)printf("%d ",ab[i][j]);
			else printf("0 ");
		}
		if(ans[i][m-1]!=0)printf("%d\n",ab[i][m-1]);
			else printf("0\n");
	}
	
	return 0;
} 
