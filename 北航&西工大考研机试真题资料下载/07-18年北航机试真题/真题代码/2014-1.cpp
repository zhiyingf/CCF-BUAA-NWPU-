#include <stdio.h>
int main()
{
	int n;
	int buf1[100];
	int buf2[100];
	scanf("%d",&n);
	printf("%d,",n);
	int m=n;
	int i=0,j=0;;
	while(m!=0)
	{
		buf1[i++]=m%10;
		m/=10;
	}
	int sum=0;
	int ans;
	for(j=0;j<i;j++)
	{
		int tmp=buf1[j];
		ans=1;
		while(tmp!=0)
		{
			ans*=tmp;
			tmp--;
		}
		sum+=ans;

	}
	for(;j-1>=0;j--)
	{
		if(j-1!=0)	printf("%d!+",buf1[j-1]);
		else	printf("%d!=%d\n",buf1[j-1],sum);
	}
	if(sum==n)	printf("Yes");
	else printf("No");
		return 0;


}