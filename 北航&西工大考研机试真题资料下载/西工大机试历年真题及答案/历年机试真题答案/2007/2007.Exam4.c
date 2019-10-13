/*
	ĳ�ʵ���2m�����ӣ�����Ҫ����ѡ��һ����̫�ӣ�
	�ʵ۲�֪���ð���һ��������Ϊ̫�ӣ����Ǿ���������ķ�����ѡ��̫�ӣ�
	��ÿ��̫�ӵı�ŷֱ�1(0)��2��3������2m(2m-1)����˳ʱ�뷽��վ��һ��ԲȦ��
	���ڴ�1(0)��̫�ӿ�ʼ��˳ʱ�뷽������������n(n-1)���ˣ�������̭���֣�
	Ȼ���������һ���˿�ʼ�������̣�����m���˱���̭ʱ��ת�䷽�������1��ʼ����
	�ظ��������̣����ʣ�µĻ��ӽ�����Ϊ̫�ӡ���������дһ������
	��������Ż��ӽ�����Ϊ̫�ӡ�
	�������ݣ���������������m n
	������ݣ����̫�ӵı��
	Sample input
	3 3
	Sample output
	1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* prior;
	struct Node* next;
}sonNode;

sonNode* Create()
{
	sonNode *p;

	if(!(p = (sonNode*)malloc(sizeof(sonNode))))
	{
		printf("Not enough!\n");
		exit(0);
	}

	
	p->data = 0;
	p->prior = p;
	p->next = p;

	return p;

}

void Initiate(sonNode* son, int n)
{
	sonNode *p, *q;
	int k = 0;

	q = son->next;
	
	while(k < n - 1)
	{
		if(!(p = (sonNode*)malloc(sizeof(sonNode))))
		{
			printf("Not enough!\n");
			exit(0);
		}
		p->data = k + 1;
		q->next = p;
		p->prior = q;
		p->next = q;
		q = p;
		k++;
	}
	q->next = son;
	son->prior = q;
}
/*
sonNode* DeleteS(sonNode* son, int m, int n)
{	//˳ʱ��ɾ��
	sonNode *p, *q;
	int i = 1, j = 0;

	p = son;
	while(j < m)
	{
		if(i < n)
		{
			p = p->next;	
			i++;
		}
		else
		{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			q = p;
		//	printf("%d ", q->data);
			p = p->next;
			free(q);
			j++;
			i = 1;
		}
	}

	return p;
}

sonNode* DeleteN(sonNode* son, int m, int n)
{	//��ʱ��ɾ��
	sonNode *p, *q;
	int i = 1, j = 0;

	p = son;
	while(j < m)
	{
		if(i < n)
		{
			p = p->prior;	
			i++;
		}
		else
		{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			q = p;
		//	printf("%d ", q->data);
			p = p->prior;
			free(q);
			j++;
			i = 1;
		}
	}

	return p;
}
*/
int Delete(sonNode* son, int m, int n)
{
	sonNode *p, *q;
	int i = 1, j = 0, flag = 1;

	p = son;
	while(flag)
	{
		i = 1;
		j = 0;
		while(j < m && flag)
		{
			if(i < n)
			{
				p = p->next;	
				i++;
			}
			else
			{
				p->prior->next = p->next;
				p->next->prior = p->prior;
				q = p;
				p = p->next;
				free(q);
				j++;
				i = 1;			
				if(p->next == p) 
					flag = 0;
			}
		}
	
		i = 1;
		j = 0;
		while(j < m && flag)
		{
			if(i < n)
			{
				p = p->prior;	
				i++;
			}
			else
			{
				p->prior->next = p->next;
				p->next->prior = p->prior;
				q = p;
				p = p->prior;
				free(q);
				j++;
				i = 1;
				if(p->prior == p) 
					flag = 0;		
			}
		}
	}

	return p->data;
}

void main()
{
	sonNode *son, *p;
	unsigned int m, n;

	scanf("%d %d", &m, &n);
	if(m == 0 || n == 0)
	{
		printf("Error!\n");
		exit(0);
	}

	son = Create();
	Initiate(son, 2 * m);
	printf("%d\n", Delete(son, m, n));

//	son = DeleteS(son, m, n);
//	son = DeleteN(son, m, n);

/*
	p = son->next;
	printf("\n%d ", son->data);
	while(p != son)
	{
		printf("%d ", p->data);
		p = p->next;
	}
*/
}