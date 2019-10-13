/*
	һ���������е����������ڸ�������ɾȥ����Ԫ�غ�õ������С�ȷ�е�˵��
	����������X=<x1, x2,��, xm>������һ����Z=<z1, z2,��, zk>��X��������
	��ָ����һ���ϸ�������±����� <i1, i2,��, ik>��ʹ�ö�������j=1,2,��,k�У�

	Xij �� Zj

	���һ������S����A������������B�������У����S��A��B�Ĺ��������С�
	��A��B���й�����������������еĳ��ȡ�
	���룺
	���빲���У�ÿ��һ������ĸ��������ɵ��ַ�������������A��B��A��B�ĳ��Ȳ�����10000���ַ���
	�����
	һ����������ʾ����������еĳ��ȡ�
	��ʽ��printf("%d\n");
	����������
	programming
	contest
	���������
	2
*/

#include <stdio.h>
#define MAX 10000

int judge(char A[], char B[], int lenA, int lenB, int i, int j, int max)
{
	int len = 0;
	if(i < lenA)
	{
		if(A[i] == B[j])
		{
			max++;
			len = judge(A, B, lenA, lenB, i + 1, j + 1, max);
		}
		else if(A[i] != B[j] && j < lenB)
				len = judge(A, B, lenA, lenB, i, j + 1, max);

		else if(j >= lenB)
				len = judge(A, B, lenA, lenB, i + 1, 0, max);
			
		if(len > max) max = len;
	}
	return max;
}


void main()
{
	char A[MAX], B[MAX], ch;
	int lenA = 0, lenB = 0, maxlen = 0;
	
	scanf("%c", &ch);
	while(ch != '\n')
	{
		A[lenA++] = ch;
		scanf("%c", &ch);
	}

	scanf("%c", &ch);
	while(ch != '\n')
	{
		B[lenB++] = ch;
		scanf("%c", &ch);
	}
	
	maxlen = judge(A, B, lenA, lenB, 0, 0, maxlen);

	printf("%d\n", maxlen);
}