/*
	ʯ�Ӻϲ�
	ʱ�ޣ�1000ms �ڴ����ƣ�10000K ��ʱ�ޣ�3000ms
	������


	��һ��Բ�βٳ������ܰڷ���n��ʯ��(n<= 100)����Ҫ��ʯ���д���غϲ���һ�ѡ�
	�涨ÿ��ֻ��ѡȡ���ڵ����Ѻϲ����µ�һ��,�����µ�һ�ѵ�ʯ����,��Ϊ�ôκϲ��ĵ÷�.
	��һ���򣬶���ʯ�Ӷ���n��ÿ�ѵ�ʯ����(<=20)��ѡ��һ�ֺϲ�ʯ�ӵķ���,
	ʹ����n��1�κϲ�,�÷ֵ��ܺ���С��������4��ʯ�ӣ�4 4 5 9 ����Ѻϲ��������£�
	4 4 5 9 score: 0
	8 5 9 score: 8
	13 9 score: 8 + 13 = 21
	22 score: 8 + 13 + 22 = 43


	���룺


	�����ж���������ݡ� ������n=0ʱ����! ��һ��Ϊʯ�Ӷ���n(1<=n<=100)��
	�ڶ���Ϊn�ѵ�ʯ��ÿ�ѵ�ʯ����,ÿ������֮����һ���ո�ָ���

	�����


	�ϲ�����С�÷֣�ÿ�����һ�С�

	����������


	4
	4 4 5 9
	0
	���������


	43

*/

#include <stdio.h>
#define MAX 100

int getscore(int n)
{
	int stone[MAX] = {0};
	int i, min, flag, score = 0;

	for(i = 0; i < n; i++)
		scanf("%d", &stone[i]);
	
	if(n == 1)	return stone[0];

	while(n > 1)
	{	
		min = stone[0] + stone[1];
		flag = 0;
		for(i = 1; i < n; i++)
			if(stone[i] + stone [(i + 1) % n] < min)
			{
				min = stone[i] + stone [(i + 1) % n];
				flag = i;
			}
		stone[flag] = min;
		score += min;
		for(i = (flag + 1) % n; i < n; i++)
			stone[i] = stone[(i + 1) % n];
		n--;
	}

	return score;

}

void main()
{
	int n;
	
	scanf("%d", &n);

	while(n != 0)
	{	
		if(n < 1 || n > 100) printf("Data is error!\n");
		else	printf("%d\n", getscore(n));
		scanf("%d", &n);
	}
}