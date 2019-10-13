/*
	Լɪ������
	ʱ�ޣ�100ms �ڴ����ƣ�10000K  ��ʱ�ޣ�1000ms
	������
	����N��ͬѧ������Χ��һȦ����1��2��3��......��ʼ��ţ��ִ�1�ſ�ʼ����������
	ÿ����M����ͬѧ��Ȧ�����ߣ� ��������ߵ�ͬѧ�ı��
	���룺
	�������������ֱ�ΪN��M��0<N<=100 ��0<M<65535
	�����
	һ����������Ϊ������ߵ�ͬѧ�ı�ţ��������س�
	����������
	100 10
	���������
	26
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}stuNode;

stuNode* Create()
{
	stuNode* stu;

	stu = (stuNode*)malloc(sizeof(stuNode));
	if(stu == NULL)
	{
		printf("Not enough!\n");
		exit(0);
	}
	stu->data = 1;
	stu->next = stu;

	return stu;
}

void Initiate(stuNode* stu, int n)
{
	stuNode *p, *q;
	int i = 1;

	q = stu;
	while(i < n)
	{
		p = (stuNode*)malloc(sizeof(stuNode));
		if(p == NULL)
		{
			printf("Not enough!\n");
			exit(0);
		}
		p->data = i + 1;
		q->next = p;
		q = p;
		i++;
	}
	q->next = stu;
}

int Delete(stuNode* stu, int m)
{
	stuNode *p, *q;
	int i = 1;

	q = stu;
	p = stu->next;
	while(q->next != q)
	{
		if((i + 1) % m == 0)
		{
			q->next = p->next;
			free(p);
			p = q->next;
		}
		else
		{
			q = p;
			p = p->next;
		}
		i++;
	}

	return q->data;
}

void main()
{
	unsigned int N, M;
	stuNode *stu, *p, *q;
	int i;

	scanf("%d %d", &N, &M);
	if(N > 100)
		printf("Error!\n");	

	stu = Create();
	Initiate(stu, N);
	printf("%d\n", Delete(stu, M));
}