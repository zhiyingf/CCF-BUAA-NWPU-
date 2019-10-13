#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	char c[100];
	int i=0;
	gets(c);
	int len=strlen(c);
	int point=0;
	for(i=0;i<len;i++)
	{
		if(c[i]=='.')	point=i;
	}
	if(point==1)
	{
		if(c[0]!='0')	puts(c);
		else
		{
			i=2;
			int zero=0;
			while(c[i]=='0')
			{
				i++;
				zero++;
			}
			printf("%c",c[i]);
			int k;
			for(k=i+1;k<len;k++)
			{
				if(k==i+1)	printf(".");
				printf("%c",c[k]);

			}
			printf("e-%d",zero+1);
		}
	}
	else if(point>0)
	{
		for(i=0;i<len;i++)
		{
			if(i==point)	continue;	
			printf("%c",c[i]);
			if(i==0) printf(".");
		}
		printf("e%d",point-1);
	}
	else
	{
		for(i=0;i<len;i++)
		{
			printf("%c",c[i]);
			if(i==0) printf(".");
		}
		printf("e%d",len-1);
	}


	return 0;
}