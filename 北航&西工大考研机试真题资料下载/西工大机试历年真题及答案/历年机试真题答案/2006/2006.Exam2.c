/*
	������ɽ������������������ٵ���������Ī�����ڼ���ȫ������¶����ʯ��
	ɽ���ҵ����ʵ�λ�ù̶�����ǣ������Ķ��ӡ�
	����������У�����Ҫ�һ�������ε�������������ҪѰ�Һ��ʵ�λ�ù̶��ĸ����ӣ�
	����ǣ����������Ľǡ���ʱ����ĳߴ粢����Ҫ�������Ǳ���ʹ������Ľ��γ�һ�������Σ�
	�������Ǳ���ʹѡȡ���ĸ����ڷ��ö��ӵĵ㹹��һ�������Ρ����ڣ�ɽ�����ܹ����ڹ̶����ӵĵ��Ѿ���ѡ����
	�������������ж������Ƿ��ܹ���һ�������Ρ�
	���룺
	�������ݰ������������tset2.txt��һ�����Ե������ļ����������ݵĵ�һ����һ������T��1<=T<=50)��
	��ʾ�������ݰ����Ĳ�������������Ǹ���һ�����зָ���T�����������ݡ�
	ÿ�����������ĸ�ѡ�еĹ̶�������꣬ÿ��������������X��Y���꣩��ʾ���е�һ���㣬
	����������һ���ո�ָ����ң�0<X,Y<1000)��ע�⣬�ĸ��㲻һ���ǰ�˳������ġ�
	�����
	����ÿһ�������Ĳ������ڵ�����һ��������жϵĽ��������������"Yes"���������"No"��

	�������룺
	3

	1 1
	1 2
	2 1
	2 2

	1 1
	2 2
	3 3
	4 4

	1 2
	2 1
	2 3
	3 2
	���������
	Yes
	No
	Yes
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
	int x;
	int y;
}coordinate;

typedef struct
{
	coordinate a;
	coordinate b;
	coordinate c;
	coordinate d;
}quadrangle;

quadrangle* LoadDate(char *filename, int *num)
{
	FILE *fp;
	int i;
	quadrangle *testdata;
	if ((fp=fopen(filename, "rt"))==NULL)
	{
		printf("File %s can not be found!\n", filename);
		exit(-1);
	}

	fscanf(fp, "%d\n\n", num);
	testdata=(quadrangle *)malloc((*num)*sizeof(quadrangle));
	for(i=0; i<(*num); i++)
	{
		fscanf(fp, "%d %d\n", &testdata[i].a.x, &testdata[i].a.y);
		fscanf(fp, "%d %d\n", &testdata[i].b.x, &testdata[i].b.y);
		fscanf(fp, "%d %d\n", &testdata[i].c.x, &testdata[i].c.y);
		fscanf(fp, "%d %d\n", &testdata[i].d.x, &testdata[i].d.y);
		fscanf(fp, "\n");
	}

	fclose(fp);
	return testdata;
}

int IsSquare(quadrangle *shape)
{
	/* Todo*/
	/* Please note: if the input shape is a square, return 1; else return 0. */
	int d1, d2, d3;

	d1 = (shape->a.x-shape->b.x) * (shape->a.x-shape->b.x) + (shape->a.y-shape->b.y) * (shape->a.y-shape->b.y);
	d2 = (shape->a.x-shape->c.x) * (shape->a.x-shape->c.x) + (shape->a.y-shape->c.y) * (shape->a.y-shape->c.y);
	d3 = (shape->a.x-shape->d.x) * (shape->a.x-shape->d.x) + (shape->a.y-shape->d.y) * (shape->a.y-shape->d.y);

	if(d1 < d2)	
	{
		if(d1 + d3 == d2)	return 1;
		else return 0;
	}
	if(d1 < d3)
	{
		if(d1 + d2 == d3)	return 1;
		else return 0;
	}
	if(d2 < d1)
	{
		if(d2 + d3 == d1)	return 1;
		else return 0;
	}
	/* Todo*/
}

main()
{
	int number;
	int i;
	int result;

	quadrangle *data;
	data = LoadDate("06test2.txt", &number);

	for (i=0; i<number; i++)
	{
		result = IsSquare(&data[i]);
		if (result)
			printf("Yes\n");
		else
			printf("No\n");
	}

	if (data != NULL)
		free(data);
}