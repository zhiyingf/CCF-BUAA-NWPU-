/*
	�Ѹ���������һ�ö��������㷨������������ಿ�֣�
	�����������򡢺����������������ӡ������
	�������н�����������˳������ַ�ΪA B C �� �� D  E �� G �� �� F �� �� ����
	ע������ʱ���ÿո���档��40�֣�
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char e;
    struct BiTNode *lchild,*rchild;
}BiTNode;

/*
	Implement the following parts as ToDo
*/

void preOrderTraverse(BiTNode *T1)
{
		/*  ToDo*/
	if(T1 != NULL)
		printf("%c ", T1->e);
	preOrderTraverse(T1->lchild);
	preOrderTraverse(T1->rchild);
}

void inOrderTraverse(BiTNode *T1)
{
		/*  ToDo*/
	preOrderTraverse(T1->lchild);
	if(T1 != NULL)
		printf("%c ", T1->e);
	preOrderTraverse(T1->rchild);
}

void postOrderTraverse(BiTNode *T1)
{
		/*  ToDo*/
	preOrderTraverse(T1->lchild);
	preOrderTraverse(T1->rchild);
	if(T1 != NULL)
		printf("%c ", T1->e);
}

int CreateBiTree(BiTNode **T1)
{

    char ch, a;
    scanf("%c%c", &ch, &a);

	if(ch == '#')	return;

    if (ch == '  ') 
    {
		/*  ToDo*/
		(*T1) = NULL;
    }
    else
	{
		/*  ToDo*/
		if(!((*T1)=(BiTNode *)malloc(sizeof(BiTNode))))  exit(0);
		(*T1)->e = ch;

		CreateBiTree(&((*T1)->lchild));
		CreateBiTree(&((*T1)->rchild));
	}
    return 1;
}

main()
{
	BiTNode *T;
	/*
	Call CreateBiTree() function
	*/
	CreateBiTree(&T);
	/*
	Call three different Traverse functions
	*/
	preOrderTraverse(T);
	inOrderTraverse(T);
	postOrderTraverse(T);
}
