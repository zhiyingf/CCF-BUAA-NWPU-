#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int i,j,k;
	FILE *fp=fopen("C:\\Users\\Administrator\\Desktop\\filein.txt","r");
	FILE *fo=fopen("C:\\Users\\Administrator\\Desktop\\fileout.txt","w");
	if(fp==NULL)	printf("√ª’“µΩ");
	char buf[100];
	char del[10];
	scanf("%s",del);
	int len=strlen(del);
	for(i=0;i<len;i++)
		del[i]=tolower(del[i]);
	while(fgets(buf,100,fp)!=NULL)
	{
		int buftmp[100];
		int len1=strlen(buf);
		for(i=0;i<len1;i++)
		{
			buftmp[i]=tolower(buf[i]);
		}
		for(i=0;i<len1;i++)
		{
			int tmp=i;
			if(buf[i]==' ') continue;
			for(k=0;k<len;k++)
			{
				if(buftmp[tmp]==del[k])
				{
					tmp++;
				}
				else
				{
					break;
				}
			}
			if(k==len)
			{
				i=tmp-1;
			}
			else
			{
				printf("%c",buf[i]);
			}
			
		}
		memset(buf,'\0',100);
	}
	fclose(fp);
	fclose(fo);
	return 0;
}
