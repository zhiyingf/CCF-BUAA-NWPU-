#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
bool ifchar(char c)
{
	if(c>='a'&&c<='z')
		return true;
	return false;
}
bool ifsym(char b)
{
	if(b==' '||b==','||b=='.'||b=='?'||b=='\n')
		return true;
	return false;
}
int cmp(char c1[],char c2[])
{
	int len1=strlen(c1);
	int len2=strlen(c2);
	int min= len1<len2?len1:len2;
	int i;
	for(i=0;i<min;i++)
	{
		if(c1[i]==c2[i])	continue;
		else if(c1[i]<c2[i])	return -1;
		else if(c1[i]>c2[i])	return 1;
	}
	return 0;
}
struct Aim
{
	int idx;
	char words[100];
	bool operator < (const Aim &A) const
	{
		return idx<=A.idx;
	}
}aim[100];

char buf[10000];
int main()
{
	char c;
	int i=0;
	int j=0,k=0;
	while(scanf("%c",&c)!=EOF)
	{
		buf[i++]=c;

	}
	int len=i;
	for(i=0;i<len;i++)
	{
		if(ifchar(buf[i]))
		{
			aim[j].words[k]=buf[i];
			k++;
		}
		if(ifsym(buf[i]))
		{
			while(ifsym(buf[i]))	i++;
			i--;
			j++;
			k=0;
		}
	}
	for(i=0;i<j;i++)	aim[i].idx=0;
	for(i=0;i<j;i++)
	{
		for(k=i+1;k<j;k++)
		{
			if(cmp(aim[i].words,aim[k].words)>0)	
			{
				aim[i].idx++;
			}
			else aim[k].idx++;
		}
	}
	sort(aim,aim+j);
	for(i=0;i<j;i++)
	{
		if(i==0)	printf("%s ",aim[i].words);
		if(cmp(aim[i].words,aim[i-1].words)==0)	
			continue;
		printf("%s ",aim[i].words);
	}

	return 0;
}