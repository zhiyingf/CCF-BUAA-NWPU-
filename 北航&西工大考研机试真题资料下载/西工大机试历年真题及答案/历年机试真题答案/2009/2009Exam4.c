/*
	N�ʺ�����
	ʱ�ޣ�1000ms �ڴ����ƣ�10000K  ��ʱ�ޣ�3000ms
	������
	���N�ʺ��������в�ͬ�İڷ����������
	���룺
	����һ������n(3<n<=20),��ʾ��n*n�����̣��ܹ��ڷ�n���ʺ�
	�����
	����ܹ���ͬ�İڷ�����������������һ�С�
	����������
	4
	���������
	2
	��ʾ��
	�����ʽΪprintf("%d\n",count);
*/

#include <stdio.h>
#define MAX 20

int Queen(int n)
{
	int pan[MAX][MAX] = {0}, queen[MAX] = {0};
	int i = 0, j = 0, k = 0, count = 0;

	for(i = 0; i < n; i++)
		queen[i] = i + 1;

	while(k < n)
	{
		pan[i][j] = queen[k];
		if(jadge())
	}
}

void main()
{
	int n, count;

	scanf("%d", &n);
	if(n <= 3 || n > 20)
	{
		printf("Error!\n");
		exit(0);
	}

	count = Queen(n);

	printf("%d\n",count);
}

