#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y;
	char ch;
	scanf("%d%d%d",&n,&x,&y);
	getchar();
	scanf("%c",&ch);
	int n1=n-1;
	bool flag=true;
	if(x==0&&ch=='w')flag=false;
	else if(x==n1&&ch=='s')flag=false;
	if(y==0&&ch=='a')flag=false;
	else if(y==n1&&ch=='d')flag=false;
	if(flag)printf("Y\n");
	else printf("N\n");
	return 0;
} 
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int m,t;
char str;
int main()
{
    cin>>t;
    cin>>n>>m;
    cin>>str;
    if(str=='w'){
        if(n==0) printf("N\n");
        else printf("Y\n");
    }
    else if(str=='s'){
          if(n==t-1) printf("N\n");
        else printf("Y\n");
    }
    else if(str=='a'){
          if(m==0) printf("N\n");
        else printf("Y\n");
    }
    else if(str=='d'){
          if(m==t-1) printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
**/ 
