/**
使用DP来求解--任意两点间的最短路问题（Floyd-Warshall算法）
只使用i和j的情况下，记i到j的最短路长度为d[k+1][i][j]。k=-1时，认为只使用i和j，所以d[0][i][j]=cost[i][j]。接下来
把只使用顶点0~k的问题归约到只使用0~k-1的问题上。
只使用0~k时，我们分 i到j的最短路 正好经过顶点k一次（d[k][i][j]=d[k-1][i][j]）
和完全不经过顶点k两种情况来讨论(d[k][i][j]=d[k-1][i][k]+d[k-1][k][j])。 
d[i][j]=min(d[i][j],d[i][k]+d[k][j])
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_V=102;
int V;
int d[MAX_V][MAX_V];//d[u][v]表示边e=(u,v)的权值（不存在时设为INF,不过d[i][i]=0） 
void warshall_floyd(){
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}
