#include <stdio.h>
int sum[10000];
bool mark=false;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=m;i<=n;i++)
	{
		sum[i]=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)	sum[i]+=j;
		}
	}
	for(i=m;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(sum[i]==j&&sum[j]==i)
			{
				printf("%d %d\n",i,j);
				mark=true;
			}
		}
	}
	if(mark==false)	printf("NONE");
	return 0;
}