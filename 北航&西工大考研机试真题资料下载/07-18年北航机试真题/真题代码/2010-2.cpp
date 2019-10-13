#include <stdio.h>
#include <string.h>
int main()
{
	char a[100],b[100],c[100];
	int i,j,k;
	scanf("%s%s",a,b);
	int len1=strlen(a);
	int len2=strlen(b);
	i=j=k=0;
	while(i<len1&&j<len2)
	{
		if(a[i]<b[j])	c[k++]=a[i++];
		if(a[i]>b[j])	c[k++]=b[j++];
		if(a[i]==b[j])	
		{
			c[k++]=a[i++];
			j++;
		}
	}
	while(i<len1)	c[k++]=a[i++];
	while(j<len2)	c[k++]=b[j++];
	for(i=0;i<k;i++)
		printf("%c",c[i]);
	return 0;
}