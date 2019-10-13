#include <stdio.h>
bool atk(int c1,int c2,int i, int j)//列 列 行 行
{
	if(c1==c2||c1-c2==i-j||c2-c1==i-j)
		return true;
	return false;
}
int c[20],n=8,cnt=0;
void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==c[i])	printf("1");
			else printf("0");
		}		printf("\n");

	}
}
void eight(int r)
{
	if(r==n)
	{
		print();
		++cnt;
		return;
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		c[r]=i;
		int ok=1;
		for(j=0;j<r;j++)
		{
			if(atk(c[r],c[j],r,j))
			{
				ok=0;
				break;
			}
		}
		if (ok)	eight(r+1);

	}


}
int main()
{
	eight(0);
	printf("%d",cnt);
	return 0;
}