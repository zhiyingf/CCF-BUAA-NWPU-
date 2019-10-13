#include <stdio.h>
int i;
double formular(int x,double y,int n)
{
	double tmp=y*2/3+x/(3*y*y);
	if(i==n)	
	{	
		i=0;
		return tmp;
	}
	else 
	{		
		i++;
		return	formular(x,tmp,n);
	}
}
int main()
{
	int x,n;
	while(scanf("%d%d",&x,&n)!=EOF)
	{
		printf("%.6f\n",formular(x,x,n));
	}
	return 0;
}
