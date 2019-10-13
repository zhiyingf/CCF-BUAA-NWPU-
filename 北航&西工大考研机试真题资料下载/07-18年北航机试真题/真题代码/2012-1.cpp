#include <stdio.h>
int main()
{
	int n;
	bool mark=false;
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			int sum=(i+j)*(j-i+1)/2;
			if(sum==n)
			{
				mark=true;
				for(k=i;k<=j;k++)
				{
					printf("%d ",k);
				}
				printf("\n");
			}
			if(sum>n)	break;
		}
	}
	if(!mark)	printf("NONE");
	return 0;
}