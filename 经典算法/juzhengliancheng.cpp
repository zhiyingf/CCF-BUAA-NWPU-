#include<iostream>
#include<string.h>
using namespace std;
const int N = 10000;
int p[N], m[N][N], s[N][N];
int n;//�������
int matrixchain(int n)
{
	memset(s, 0, sizeof(s));
	memset(m, 0, sizeof(m));
	for (int r = 2; r <= n; r++)//��ͬ��ģ��������
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = r + i - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//����Ϊk=i�ĳ˷����� 
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
			//cout<<"i="<<i<<"j="<<j<<"m="<<m[i][j]<<"*"<<endl;
		}
	}
	return m[1][n];
}
//׷�ݷ�
void print(int i,int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
		return;
	}
	cout << "(";
	print(i, s[i][j]);
	print(s[i][j] + 1, j);
	cout << ")";
}
int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> p[i];//����ÿ����������������һ�����������
	cout << "��С��������ֵΪ��" << endl;
	cout << matrixchain(n) << endl;
	print(1, n);
	return 0;
}

