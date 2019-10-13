/*
	һ��nλ��������n��������󣬱��ο���n�ķ�Χ��1~5000�������ָ���ָ�����ָ�λ����֮�͡�
	�������һ����λ������ô������־����������ָ���������Ǹ���λ�������λ�����֣���ô�ͼ������ֱ���õ���λ����
	���磺����24����2��4��ӣ��õ�6����ô6����24�����ָ���
	�ֱ�������39��������3��9��ӣ��õ�12����Ϊ12ʱ��λ�������Լ�����1��2��ӣ��õ�3������3����39�����ָ���
	Ҫ��
	ʹ������洢��������ݣ������ڼ���Ĺ�����ʹ������洢�м����Ľ������ɱ���Ŀ�Ĺ��ܡ�
	���룺
	���뽫����һ����������ÿ��ֻ��һ�����ִ�����һ���н�������0ʱ����ʾ���������
	�����
	����ÿһ����������������ڵ�����һ��������������ָ���
	�������룺
	24
	39
	0
	���������
	6
	3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	unsigned char bit;
	struct _node *link;
}node;

typedef struct 
{
	node* head;
	int length;
}LinkedList;

int calculateRoot(LinkedList la)
{
	int root=0;
	node *p;
	/* To Do */
	p = la.head;
	while(p->link != NULL)
	{
		root += p->link->bit;
		p = p->link;
	}
	while(root > 9)
	{
		//��������
		p = la.head->link;
		p->bit = root % 10;
		p->link->bit = root / 10;
		p->link->link = NULL;
		root = calculateRoot(la);
	}
		
	/* To Do */
	
	return root;
}

LinkedList InputData()
{
	LinkedList la;
	char str[5000];
	char *p;
	int len=0;
	node *temp;

	gets(str);
	la.length=0;
	la.head=(node*)malloc(sizeof(node));
	la.head->bit=0;
	la.head->link=NULL;

	p=str;

	if (*p != '0')
	{
		while (*p != '\0')
		{
			temp = (node*)malloc(sizeof(node));
			temp->bit = (*p) - '0';
			temp->link = la.head->link;
			la.head->link=temp;
			p++;
			la.length++;
		}
	}

	return la;
}

void freeList(LinkedList la)
{
	node *head, *temp;

	head=la.head->link;
	while (head != NULL)
	{
		temp = head;
		head = head->link;
		free(temp);
	}
	free(la.head);

}

void main()
{

	LinkedList la;
	int numberRoot;
	for (;;)
	{
		la=InputData();
		if (la.length == 0)
		{
			freeList(la);
			break;
		}
		numberRoot = calculateRoot(la);
		printf("the root of this number is %d\n",numberRoot);
		freeList(la);
	}
}
