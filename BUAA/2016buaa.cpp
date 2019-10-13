#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	char str[11]="";
	char str1[11]="";
	scanf("%d",&n);
	printf("%s",str);
	sprintf(str,"%d",n);
	int j=0;
	for(int i=strlen(str)-1;i>=0;i--){
		str1[j++]=str[i];
	}
	str1[strlen(str)]='\0';
	
	return 0;
}
