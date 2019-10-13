#include<iostream>
#include<string.h>
using namespace std;
const int N = 10000;
int p[N], m[N][N], s[N][N];
int n;//矩阵个数
int matrixchain(int n)
{
	memset(s, 0, sizeof(s));
	memset(m, 0, sizeof(m));
	for (int r = 2; r <= n; r++)//不同规模的子问题
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = r + i - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//决策为k=i的乘法次数 
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
//追溯法
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
		cin >> p[i];//输入每个矩阵的行数和最后一个矩阵的列数
	cout << "最小计算量的值为：" << endl;
	cout << matrixchain(n) << endl;
	print(1, n);
	return 0;
}

