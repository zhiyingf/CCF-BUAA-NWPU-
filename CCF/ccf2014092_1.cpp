#include<bits/stdc++.h>
using namespace std;
const int N=102;
int g[N][N]={false};

int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		for(int u=x;u<xx;u++){
			for(int v=y;v<yy;v++){
				if(!g[u][v]){
					ans++;
					g[u][v]=true;
				}
			}
		}
		
	}
	printf("%d\n",ans);
	
	return 0;
}
