#include<bits/stdc++.h>
using namespace std;
//判断n是不是一个素数 
bool isPrime(int n){
	if(n<=1)return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)return false;
	}
	return true;
}
//素数表的获取
const int maxn=101;
int prime[maxn],pN=0;
int FindPrimeTable(int a,int b){
	for(int i=a;i<=b;i++){
		if(isPrime(i)){
			prime[pN++]=i;
		}
	}
	return pN;
}
 
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int n=FindPrimeTable(a,b);
	int first=0;
	for(int i=first;i<n-2;i++){
		int dif=prime[i+1]-prime[i],t1;
		if(dif==prime[i+2]-prime[i+1]){
			printf("%d %d %d",prime[i],prime[i+1],prime[i+2]);
			t1=i+2;
			while(dif==prime[t1+1]-prime[t1]&&t1+1<n){
				printf(" %d",prime[++t1]);
			}
			first=t1;
			printf("\n");
		}else first++;
		cout<<endl;
		cout<<first<<endl;
	}
	return 0;
} 
