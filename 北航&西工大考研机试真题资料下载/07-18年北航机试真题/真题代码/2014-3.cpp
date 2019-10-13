#include <stdio.h>
#include <string>
using namespace std;
char buf[50][100];
char aim[10][20];
bool ifsym(char c)
{
	if(c==' '||c=='\t')	return true;
	return false;
}
int main()
{	
	int i=0;
	int j=0;
	int k,m;
	for(i=0;i<50;i++)	
	{
		gets(buf[i]);
		if(buf[i][0]=='\0')	break;
	}
	int num=i;
	int n;
	scanf("%d",&n);
	printf("%d\n",num);
	for(i=0;i<num;i++)//iÊÇÐÐºÅ
	{
		memset(aim,0,200);
		k=0;
		m=0;
		int space=0;
		int cnum=0;
		int len=strlen(buf[i]);
		for(j=0;j<len;j++)
		{
			if(buf[i][j]==':')	
			{
				space=k;
				aim[k++][0]=':';
				m=0;
			}
			else	if(!ifsym(buf[i][j]))	aim[k][m++]=buf[i][j];
			else
			{
				while(ifsym(buf[i][j]))
				{
					j++;
				}
				j--;
				k++;
				cnum+=m;
				m=0;
			}
		}

			int p=n-1-cnum-k;
			while(p--!=0)	printf(" ");
			int q;
			for(q=0;q<space;q++)
			{
				printf("%s ",aim[q]);
			}
			printf(":");
			for(q=space+1;q<k;q++)
			{
				printf(" %s",aim[q+1]);
			}
			printf("\n");

	}
	return 0;

}