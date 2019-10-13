#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main(){
	int n,x,y,ch;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cin>>x>>y>>ch;
	
	int n1=n-1;
	bool flag=true;
	//在边缘 
	if(x==0&&ch==3)flag=false;
	else if(x==n1&&ch==1)flag=false;
	if(y==0&&ch==0)flag=false;
	else if(y==n1&&ch==2)flag=false;
	//不在边缘，或者在边缘没排除 
	if(flag){
		if(ch==0&&a[x-1][y])flag=false;
		else if(ch==1&&a[x][y+1])flag=false;
		else if(ch==2&&a[x+1][y])flag=false;
		else if(ch==3&&a[x][y-1])flag=false;
	}
	if(flag)printf("Y\n");
	else printf("N\n");
	return 0;
} 
//从方向的角度考虑，即以前进的方向为主体讨论 
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int m,t;
int str;
int mat[107][107];
int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
        for(int j=0;j<t;j++)
    {
        scanf("%d",&mat[i][j]);
    }
    cin>>n>>m;
    cin>>str;
    if(str==0){
        if(m-1>=0&&mat[n][m-1]==0) printf("Y\n");
        else printf("N\n");
    }
    else if(str==1){
       if(n+1<t&&mat[n+1][m]==0) printf("Y\n");
        else printf("N\n");
    }
    else if(str==2){
       if(m+1<t&&mat[n][m+1]==0) printf("Y\n");
        else printf("N\n");
    }
    else if(str==3){
           if(n-1>=0&&mat[n-1][m]==0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

**/ 

