/*
	���ݶ�������������������У�����㷨�ع�����ö���������40�֣�
	��֪һ�ö��������������������ABECDFGHIJ���������������EBCDAFHIGJ��
	�����һ���㷨������ö������Ľṹ�ع�������
	���������������������ȱ����Ľ��������������ͺ������У���
*/

#include <stdio.h>

typedef struct BiTNode
{
    char e;
    struct BiTNode *lchild,*rchild;
}BiTNode;

/*
	Implement the following parts as ToDo
*/

void preOrderTravse(BiTNode *T1)
{
		/*  ToDo*/
}

void inOrderTravse(BiTNode *T1)
{
		/*  ToDo*/
}

void postOrderTravse(BiTNode *T1)
{
		/*  ToDo*/
}

int CreateBiTree(BiTNode **T1, char *preString, char *inString, int start, int end)
{

    if (start == end) 
    {
		/*  ToDo*/
    }
    else
		{
			/*  ToDo*/
			
			CreateBiTree(&((*T1)->lchild), preString, inString, start, middle);
			CreateBiTree(&((*T1)->rchild) , preString, inString, middle+1, end);
		}
    return 1;
}

main()
{
		/*
		Call CreateBiTree() function
		*/
		CreateBiTree();

		/*
		Call three different Travse functions
		*/
		preOrderTravse();
		inOrderTravse();
		postOrderTravse();

}
