/*
	��֪k���Შ�������еĶ���Ϊf0=0��f1=0������fk-2=0, fk-1=1�� fn=fn-1+fn-2+��+fn-k��n=k��k+1������
	�Ա�д��k���Შ�������еĵ�m��ֵ�ĺ����㷨��k��m����ֵ���õ���ʽ�ں����������г��֡�
	�������ݣ���������������k m(����1<k<m�������������ݶ��ڳ��������ݵķ�Χ֮��)
	������ݣ����k���Შ�������еĵ�m��ֵfm��
	��ע�⣺�������漰���������ݶ��ڳ��������ݵķ�Χ֮�ڣ�
	Sample input
	2 3
	Sample output
	2
*/

#include <stdio.h>
#define MAXSIZE 100

int feibonaqi(long int k, long int m)
{
	int i, j, count = 0, f[MAXSIZE] = {0};

	f[k - 1] = 1;
	for(i = k; i <= m; i++)
		for(j = i - k; j < i; j++)
			f[i] += f[j];
	return f[m];
}

void main()
{
	long int k, m;

	scanf("%d %d", &k, &m);
	if(k <= 1 || k >= m)
	{
		printf("Input Error!\n");
		exit(0);
	}

	printf("%d\n", feibonaqi(k, m));
}