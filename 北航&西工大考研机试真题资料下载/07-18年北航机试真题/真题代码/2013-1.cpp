#include <stdio.h>
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int i;
	int min=m<n?m:n;
	for(i=2;i<=min;i++)
	{
		if(m%i==0&&n%i==0)
		{
			m/=i;
			n/=i;
			min/=i;

		}
	}	
	printf("%d %d",m,n);

	return 0;
}