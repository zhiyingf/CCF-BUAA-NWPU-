#include <stdio.h>
int buf[100][100];
struct Row
{
	int start;
	int end;
}row[100];
struct Col
{
	int start;
	int end;
}col[100];
int main()
{
	int n;
	int ans=0;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<100;i++)
	{
		row[i].start=0;
		row[i].end=0;
		col[i].start=0;
		col[i].end=0;

	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&buf[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(buf[i][j]==0)	continue;
			else 
			{
				row[i].start=j;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=n;j>row[i].start;j--)
		{
			if(buf[i][j]==0)	continue;
			else 
			{
				row[i].end=j;
				break;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(buf[i][j]==0)	continue;
			else
			{	
				col[j].start=i;
				break;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		for(i=n;i>col[j].start;i--)
		{
			if(buf[i][j]==0)	continue;
			else
			{
				col[j].end=i;
				break;
			}
		}
	}
	for(i=1;i<n-1;i++)
	{
		for(j=1;j<n-1;j++)
		{
			if(buf[i][j]==0)
			{
				if(j>row[i].start && j<row[i].end && i>col[j].start && i<col[j].end)
				{
					ans++;
//					printf("%d,%d\n",i+1,j+1);
				}
			}
		}
	}
	printf("%d\n",ans);
//	printf("%d,%d,%d,%d",row[4].start,row[4].end,col[2].start,col[2].end);
	return 0;
}
/*
1 1 1 1 1 1
1 1 0 0 0 1
1 0 0 0 1 0
1 1 0 1 1 1
0 1 0 1 0 0
1 1 1 1 1 1
*/