#include <stdio.h>
#include <string>
using namespace std;
int cmp(char c)
{
	if(c>='0'&&c<='9')	return 0;
	if(c>='a'&&c<='z')	return 1;
	if(c>='A'&&c<='Z')	return 2;
	if(c=='-')	return 3;
	return -1;
}
char buf[100];
int main()
{
	gets(buf);
	int len=strlen(buf);
	int i,k;
	for(i=0;i<len;i++)
	{
		if(cmp(buf[i])==3)
		{
			if(cmp(buf[i-1])==cmp(buf[i+1]))
			{
				for(k=1;k<buf[i+1]-buf[i-1];k++)
				{
					printf("%c",buf[i-1]+k);
				}
			}
			else
				printf("%c",buf[i]);
		}
		else
			printf("%c",buf[i]);
	}
	return 0;
}
