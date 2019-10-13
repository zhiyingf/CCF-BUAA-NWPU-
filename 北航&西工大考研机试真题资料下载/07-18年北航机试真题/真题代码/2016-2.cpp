#include <stdio.h>
#include <string>
using namespace std;
bool cmp(char c)
{
	if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z')||c=='_')
		return true;
	return false;
}
int change(char p[])
{
	int len=strlen(p);
	int i;
	int num=0;
	int pow=1;
	for(i=len-1;i>=0;i--)
	{
		num+=(int)(p[i]-'0')*pow;
		pow*=10;
	}
	return num;
}
char s1[1000];
char aim[100][20];
/*int main()
{ 
		printf("%d",change(gets(s1)));
		return 0;
}*/

int main()
{
	gets(s1);
	int len=strlen(s1);
	int i,j,k,s,num;
	char Num[10];
	s=0;
//	printf("%d",len);
	for(i=0;i<len;i++)
	{
		if(cmp(s1[i]));
		if(s1[i]==' ')
		{
			while(s1[i]==' ')	i++;
			i--;
		}
		if(cmp(s1[i]));
		if(s1[i]=='{')
		{
			s=i+1;
//			printf("%d",s);
		}
	}						

	j=0;k=0;
	num=0;
	for(i=s;i<len;i++)
	{
		if(cmp(s1[i]))
		{
			aim[j][k++]=s1[i];
		}
		else if(s1[i]=='=')
		{
			i++;
			int m=0;
			while(cmp(s1[i]))
			{
				Num[m++]=s1[i++];
			}
			Num[m]='\0';
//			printf("%s\n\n\n\n",Num);
			num=change(Num);
			i--;

		}
		else if(s1[i]==','||s1[i]=='}')
		{
			printf("%s%d\n",aim[j],num);
			j++;
			k=0;
			num++;
		}
	}
//	printf("%d",s);
	return 0;
}