#include<bits/stdc++.h>
using namespace std;
int a[502][502];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int x,y;
	for(int i=1;i<=n;i++){
		if((i%2)==1){
			x=i;y=1;
			while(x>=1){
				printf("%d ",a[x--][y++]);
			}
		}else{
			x=1;y=i;
			while(y>=1){
				printf("%d ",a[x++][y--]);
			}
		}
	}
	for(int i=n-1;i>=1;i--){
		if((i%2)==1){
			x=n;y=n-i+1;
			while(y<=n){
				printf("%d ",a[x--][y++]);
			}
		}else{
			x=n-i+1;y=n;
			while(x<=n){
				printf("%d ",a[x++][y--]);
			}
		}
	}
	return 0;
}
