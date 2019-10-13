#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans1[100],ans2[100];
	int i,j,k;
	int sum1=0,sum2=0;;
	j=0;k=0;
	printf("%d,",a);
	for(i=1;i<a;i++)
	{
		if(a%i==0)	
		{
			ans1[j++]=i;
			if(i==1)	printf("%d",ans1[j-1]);
			else printf("+%d",ans1[j-1]);
			sum1+=ans1[j-1];
		}
	}
	printf("=%d\n",sum1);
	printf("%d,",b);
	for(i=1;i<b;i++)
	{
		if(b%i==0)
		{
			ans2[k++]=i;
			if(i==1)	printf("%d",ans2[k-1]);
			else printf("+%d",ans2[k-1]);
			sum2+=ans2[k-1];	
		}
	}
	printf("=%d\n",sum2);
	if(sum1==b&&sum2==a) printf("1");
	else printf("0");
	return 0;

}