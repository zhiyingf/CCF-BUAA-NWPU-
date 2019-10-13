#include<bits/stdc++.h>
using namespace std;
struct point{
	int left;
	int right;
}a1[2002],b1[2002];
bool cmp(point a,point b){
	return a.right<b.right;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a1[i].left,&a1[i].right);
	}
	for(int i=0;i<n;i++){
		scanf("%d%d",&b1[i].left,&b1[i].right);
	}
	sort(a1,a1+n,cmp);
	sort(b1,b1+n,cmp);
	int ai=0,bi=0,ans=0;
	while(ai<n&&bi<n){
		int aleft=a1[ai].left;
		int aright=a1[ai].right;
		int bleft=b1[bi].left;
		int bright=b1[bi].right;
		//printf("aleft=%d aright=%d\n",aleft,aright);
		if(aright>=bright){
			if(aleft>=bright){
				bi++;
				continue;
			}else{
				if(bleft>=aleft){
					ans+=bright-bleft;
					bi++;
					continue;
				}else{
					ans+=bright-aleft;
					bi++;
					continue;
				}
			}
		}else{
			if(aright<=bleft){
				ai++;
				continue;
			}else{
				if(aleft<=bleft){
					ans+=aright-bleft;
					//printf("ans=%d\n",ans);
					ai++;
					continue;
				}else{
					ans+=aright-aleft;
					ai++;
					continue;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
