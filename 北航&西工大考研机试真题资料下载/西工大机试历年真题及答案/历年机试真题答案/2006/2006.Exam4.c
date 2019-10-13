/*
	�����Ҵ����������ֱ���c1��c2��n����װ�䣬������wi (i=1��n)��
	�����м�װ���������������c1+c2��ȷ���Ƿ��п��ܽ����м�װ��ȫ��װ�����Ҵ���

	���룺
	���ļ�test4.txt�м��ڲ������ݡ�
	������һ������m��Ȼ������m��������ݡ�
	ÿ��������ݽ�����һ����������ÿ��ֻ��һ�����֡���������������c1�� c2��n��Ȼ������n����װ���������
	�����
	Yes��No��ÿ�����ռһ�С�

	�������룺
	2
	50
	39
	3
	27
	20
	35
	100
	200
	2
	201
	5
	���������
	Yes
	No
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int c1;
	int c2;
	int n;
	int *p;
} Sample;


Sample* LoadData(char *filename, int *SampleNum)
{
	FILE *fp;
	int i;
	int j;
	int number;
	Sample *testdata;

	if ((fp=fopen(filename, "rt"))==NULL)
	{
		printf("File %s can not be found!\n", filename);
		exit(-1);
	}
	fscanf(fp, "%d\n\n", SampleNum);
	testdata=(Sample *)malloc((*SampleNum)*sizeof(Sample));
	for(i=0; i<(*SampleNum); i++)
	{
		fscanf(fp, "%d\n", &testdata[i].c1);
		fscanf(fp, "%d\n", &testdata[i].c2);
		fscanf(fp, "%d\n", &testdata[i].n);
		
		testdata[i].p=(int*)malloc(testdata[i].n*sizeof(int));
		for (j=0; j<testdata[i].n; j++)
		{
			fscanf(fp, "%d\n", &testdata[i].p[j]);
		}
	}

	fclose(fp);
	return testdata;
}

int CanLoading(Sample data)
{
	/* Todo*/
	/* Please note: if the data can be loaded, return 1; else return 0. */
	int i, count = 0, flag = 1;

	for(i = 0; i < data.n; i++)
	{
		count += data.p[i];
		if(data.p[i] > data.c1 || data.p[i] > data.c2)
			flag = 0;
	}
	if(count > data.c1 + data.c2 || flag == 0)
		return 0;
	else return 1;
	/* Todo*/
}

void main()
{

	int i, j, count;
	Sample * data;
	data = LoadData("06test4.txt", &count);
	for(i=0; i<count; i++)
	{
		if (CanLoading(data[i]))
			printf("Yes\n");
		else
			printf("No\n");
	}

	/*free memory */

	for(i=0; i<count; i++)
	{
		if (data[i].p != NULL)
		{
			free(data[i].p);
			data[i].p = NULL;
		}
	}

	if (data != NULL)
	{
		free(data);
		data = NULL;
	}
	/*free memory */

}
