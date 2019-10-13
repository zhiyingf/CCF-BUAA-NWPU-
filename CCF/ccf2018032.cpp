#include<bits/stdc++.h>
using namespace std;
struct _pair{
	int a,b;
}ab[1003];
int acopy[1003];
bool cmp1(const _pair pa1,const _pair pa2){
	return pa1.a<pa2.a;
}
bool cmp2(const _pair pa1,const _pair pa2){
	return pa1.b<pa2.b;
}

int main(){
	int n,l,t;
	scanf("%d%d%d",&n,&l,&t);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		ab[i].a=x;
		ab[i].b=i;
	}
	sort(ab,ab+n,cmp1);
	for(int i=0;i<n;i++){
		int t1=t,a=ab[i].a,x;
		if(t1<=l-a){
			x=a+t1;
		}else{
			t1=(t1-(l-a))%(2*l);
			if(t1<=l){
				x=l-t1;
			}else x=t1-l;
		}
		acopy[i]=x;
	}
	sort(acopy,acopy+n);
	for(int i=0;i<n;i++){
		ab[i].a=acopy[i];
	}
	sort(ab,ab+n,cmp2);
	printf("%d",ab[0].a);
	for(int i=1;i<n;i++){
		printf(" %d",ab[i].a);
	}
	return 0;
}
