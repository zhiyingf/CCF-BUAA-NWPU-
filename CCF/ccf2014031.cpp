#include<bits/stdc++.h>
using namespace std;
int a[502]={0};//1Ϊ����2Ϊ�� 
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x<0){//xΪ�� 
			x=abs(x);
			if(a[x]%2==0){
				a[x]+=2;
			}else if(a[x]%2==1){
				ans++;
				a[x]-=1;
			}
		}else if(x>0){//xΪ�� 
			if(a[x]&&a[x]%2==0){
				ans++;
				a[x]-=2;
			}else{
				a[x]+=1;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
