#include <stdio.h>
#include <string>
using namespace std;
void replace(char buf[])
{
	int i;
	int len=strlen(buf);
	int L=0,R=0;
	for(i=0;i<len;i++)
	{
		if(buf[i]=='"')
		{
			if(L==0)
			{
				L=1;
			}
			else
			{
				L=0;
				R=0;
			}
		}
		else
		{
			if(L==1)
			{
				buf[i]='#';
			}
		}
	}
}
int issym(char c)
{
	if(c==' '||c=='='||c==','||c==';'||c=='<'||c=='>'||c=='('||c==')'||c=='{'||c=='}' )
		return 1;
	return 0;
}
int getWord(char input[], int pos, char word[])
{
	int len=strlen(input);
	int i;
	int isbegin=0;
	int wpos=0;
	for(i=pos;i<len;i++)
	{
		if(issym(input[i]))
		{
			if(isbegin==0)	continue;
			else	break;
		}
		else
		{
			isbegin=1;
			word[wpos++]=input[i];
		}
	}
	word[wpos]='\0';
	return i>len?-1:i;
}
int main()
{
	char input[300];
	char word[100];
	gets(input);
//	puts(input);
	replace(input);
	int beg_pos=0;
	do
	{
		beg_pos=getWord(input,beg_pos,word);
		int wlen=strlen(word);
		if(strcmp("if",word)==0)
			printf("if:%d\n",beg_pos-wlen+1);
		else if(strcmp("while",word)==0)
			printf("while:%d\n",beg_pos-wlen+1);
		else if(strcmp("for",word)==0)
			printf("for:%d\n",beg_pos-wlen+1);

	}while(beg_pos>=0);
	
	return 0;
}