/*
�Ķ����к���˵����C���룬��Ӧ�������к��ߴ����־䣬д�ڴ𰸵Ķ�Ӧ���ڡ�
����ϻ����Գ��򣬵õ���Ӧ�������30�֣�
����һ���Ը���Ϊ������������������Ϊ5��7��2��4��9����1��
����һ����ͷ�������������ÿ������а���������ָ�룺һ����������������Ⱥ�˳��
��һ��������������������С�����˳�򡣲��ֱ�����ָ�뷽����б��������
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct NODE
{	int val  ;
	struct NODE *order;
	struct NODE *sort;
}NODE;

void main( )
{	NODE *h,*u,*v,*p,*tail;
	int d;

	h=(NODE *)malloc(sizeof(NODE));
	tail=h;
	tail->sort=NULL;

	printf("Please input data:");
	do
	{		
		scanf("%d",&d);
		if(d>0)
		{
			p=(NODE *)malloc(sizeof(NODE));
			p->val=d;
			tail->order = p;	//��1
			tail=p;
			for(u=h,v=u->sort; v&&v->val<d; v = v->sort, u = u->sort/*��2*/);
			p->sort=v;
			u->sort = p;	//��3
		}
	}while(d>0);

	p->order = NULL;	//��4
	p=h->sort;

	while(p)
	{	printf("%d,",p->val);
		p=p->sort;
	}
	printf("\n\n");

	for (p=h->order;p;p=p->order)
		printf("%d,",p->val);
	printf("\n\n");
}
