/**
ʹ��DP�����--�������������·���⣨Floyd-Warshall�㷨��
ֻʹ��i��j������£���i��j�����·����Ϊd[k+1][i][j]��k=-1ʱ����Ϊֻʹ��i��j������d[0][i][j]=cost[i][j]��������
��ֻʹ�ö���0~k�������Լ��ֻʹ��0~k-1�������ϡ�
ֻʹ��0~kʱ�����Ƿ� i��j�����· ���þ�������kһ�Σ�d[k][i][j]=d[k-1][i][j]��
����ȫ����������k�������������(d[k][i][j]=d[k-1][i][k]+d[k-1][k][j])�� 
d[i][j]=min(d[i][j],d[i][k]+d[k][j])
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_V=102;
int V;
int d[MAX_V][MAX_V];//d[u][v]��ʾ��e=(u,v)��Ȩֵ��������ʱ��ΪINF,����d[i][i]=0�� 
void warshall_floyd(){
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}
