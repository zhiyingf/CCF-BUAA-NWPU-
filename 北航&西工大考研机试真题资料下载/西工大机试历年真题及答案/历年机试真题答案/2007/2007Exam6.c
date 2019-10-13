/*
	�����б����������������ұ�������������С���߱�������������С�ұ��������������������Ϊ"����"��������ľ����а���ĸ�����

	���룺
	����ĵ�һ������������m��n�����������m��n�У�
	��������m��ÿ����n����������
	�����
	�������ĸ�������ʽ��printf("%d\n", count);
	����������
	3 4
	1 2 3 4
	6 5 8 7
	4 3 2 1
	���������
	1
*/

#include <stdio.h>
#define MAXSIZE 10

int judgeOne(int array[][MAXSIZE], int i, int j, int m, int n)
{
	if((array[i][j] > array[(i + m - 1) % m][j] && array[i][j] > array[(i + 1) % m][j]) 
		&& (array[i][j] < array[i][(j + 1) % n] && array[i][j] < array[i][(j + n - 1) % n]))
		return 1;
	else return 0;
}

int judgeTwo(int array[][MAXSIZE], int i, int j, int m, int n)
{
	if((array[i][j] < array[(i + m - 1) % m][j] && array[i][j] < array[(i + 1) % m][j]) 
		&& (array[i][j] > array[i][(j + 1) % n] && array[i][j] > array[i][(j + n - 1) % n]))
		return 1;
	else return 0;
}

void main()
{
	int array[MAXSIZE][MAXSIZE] = {0};
	int i, j, m, n, count = 0;

	scanf("%d %d", &m, &n);

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &array[i][j]);
	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(judgeOne(array, i, j, m, n) || judgeTwo(array, i, j, m, n))
				count++;

	printf("%d\n", count);
}