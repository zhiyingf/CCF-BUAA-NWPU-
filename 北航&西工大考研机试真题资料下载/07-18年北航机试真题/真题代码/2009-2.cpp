#include <stdio.h>
#include <algorithm>
using namespace std;
struct Buf
{
	int num;
	int inidx;
	int big;
	bool operator < (const Buf &A) const
	{
		return num <= A.num;
	}
}buf[100];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&buf[i].num);
		buf[i].inidx=i;
	}
	sort(buf,buf+n);
	for(i=0;i<n;i++)
	{
		buf[i].big=i;
	}
	for(i=0;i<n;i++)
	{
		if(buf[i].num==buf[i+1].num)
		{
			for(k=i+1;k<n;k++)
			{
				buf[k].big--;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(buf[j].inidx==i)
				printf("%d ",buf[j].big+1);
		}
	}

	return 0;
}