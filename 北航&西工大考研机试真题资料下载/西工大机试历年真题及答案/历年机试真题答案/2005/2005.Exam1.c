/*
Exam1.c
�ļ�a���ļ�b�и���һ�����ź�������֣�������������
�������򣬽����������ļ�c�С����磺���ļ�a��Ϊ2��4��7��14��
�ļ�b��Ϊ5��9��17����ô�������к��ļ�c��ӦΪ2��4��5��7��9��14��17��
Դ�����Ѹ�������ԭ����Ļ����ϰ�Ҫ����д
�Ӻ���MergeList( SeqList la, SeqList lb, pSeqList lc)����
*/

#include <stdio.h>

#define maxLen 100

typedef struct _SeqList
{
	int Data[maxLen];
	int size;
};

typedef struct _SeqList SeqList;
typedef struct _SeqList* pSeqList;

LoadData(char *fname, pSeqList la)
{
	FILE *fp;
	int temp;
	int i=0;
	fp = fopen(fname, "rt");
	while (!feof(fp))
	{
		fscanf(fp, "%d\n", &temp);
		la->Data[i++] = temp;
	}
	la->size = i;
	fclose(fp);
}

OutputData(char *fname, SeqList la)
{
	FILE *fp;
	int i;
	fp = fopen(fname, "wt");
	for (i=0; i<la.size; i++)
		fprintf(fp, "%d\n", la.Data[i]);
	fclose(fp);
}

/*
Implement the following parts as ToDo
*/

MergeList( SeqList la, SeqList lb, pSeqList lc)
{
		/*  ToDo*/
	int i = 0, j = 0, k = 0;

	while(i < la.size && j < lb.size)
	{
		if(la.Data[i] < lb.Data[j])
		{
			lc->Data[k] = la.Data[i];
			k++;
			i++;
		}	
		else 
		{
			lc->Data[k] = lb.Data[j];
			k++;
			j++;
		}
	}
	if(i < la.size)
		for(; i < la.size; i++)
			lc->Data[k++] = la.Data[i];
	if(j < lb.size)
		for(; i < lb.size; j++)
			lc->Data[k++] = lb.Data[j];
	lc->size = k;
}

main()
{
	SeqList la, lb, lc;
	LoadData("05test1-a.txt", &la);
	LoadData("05test1-b.txt", &lb);
	MergeList(la, lb, &lc);
	OutputData("c.txt", lc);

}
