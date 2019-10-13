#include <stdio.h>
int a[20][20];
int b[10][10];
int main()
{
	int r1,c1,r2,c2;
	scanf("%d%d",&r1,&c1);
	int i,j;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
			scanf("%d",&a[i][j]);
	}
	scanf("%d%d",&r2,&c2);
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
			scanf("%d",&b[i][j]);
	}
	int posr,posc;
	scanf("%d%d",&posr,&posc);
	posr--;posc--;
	if(posr>r1||posc>c1)
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	else
	{
		for(i=posr;i<r1&&i-posr<r2;i++)
		{
			for(j=posc;j<c1&&j-posc<c2;j++)
			{
				a[i][j]=b[i-posr][j-posc];
			}
		}
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}

	}
	return 0;

}

/*
5 6
10 2 34 -1 800 90
2 76 56 -200 23 1
35 0 0 98 8 3000
2000 100 -1 1 2 0
8 7 85 963 496 8
2 3
9 9 9
9 9 9
3 3
*/
/*
3 4
10 2 34 -1
2 76 56 -200
35 0 0 98
2 3
9 9 9
9 9 9
2 3
*/