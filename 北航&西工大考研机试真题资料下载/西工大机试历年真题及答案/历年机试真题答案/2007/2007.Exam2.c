/*
	����һ���ַ����ַ�����С��255����ͳ�����в�ͬ�Ĵ�д��Сд��ĸ�ĸ�����ÿ������ռһ�С�
	�������ݣ�һ�в������ݡ�
	������ݣ���ͬ�Ĵ�д��Сд��ĸ�ĸ�����ÿ������ռһ�С�
	Sample input
	Da; cDb����." D
	Sample output
	1
	3
*/

#include <stdio.h>

#define MAXSIZE 256

int Input(char str[])
{
	int i = 0;
	char ch;

	scanf("%c", &ch);
	while(ch != '\n')
	{
		str[i++] = ch;
		scanf("%c", &ch);
	}
	return i;
}

int countBig(char str[], int len)
{
	int i, j, count = 0;

	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			for(j = i + 1; j < len; )
			{
				if(str[i] != str[j]) j++;
				else break;
			}
			if(j >= len) count += 1;
		}
	}
	return count;
}

int countLittle(char str[], int len)
{
	int i, j, count = 0;

	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			for(j = i + 1; j < len; )
			{
				if(str[i] != str[j]) j++;
				else break;
			}
			if(j >= len) count += 1;
		}
	}
	return count;
}

void main()
{
	char str[MAXSIZE];
	int len, i;

	len = Input(str);
	printf("%d\n",countBig(str, len));
	printf("%d\n",countLittle(str, len));

}