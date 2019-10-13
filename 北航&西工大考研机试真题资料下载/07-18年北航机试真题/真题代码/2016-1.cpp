#include <stdio.h>
#include <math.h>
int main()
{
	char n[11];
	int buf[11];
	scanf("%s",n);
	int i,k;
	for(i=0;n[i]!=0;i++)
	{
		buf[i]=n[i]-'0';
	}
	int ans1=0, ans2=0;;
	for(k=0;k<i;k++)
	{
		ans1+=buf[k]*(int)pow(10,i-1-k);
		ans2+=buf[k]*(int)pow(10,k);

	}
	if(ans2%ans1==0)
		printf("%d*%d=%d",ans1,ans2/ans1,ans2);
	else 
	{
		printf("%d ",ans1);
		for(k=0;ans2/(int)pow(10,k)!=0;k++);
		int j=0;
		for(j;j<i-k;j++)
			printf("0");
		printf("%d",ans2);
	}
	return 0;

}