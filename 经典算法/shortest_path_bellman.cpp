/***
��Դ���·�㷨Bellman-Ford 
����ͼ 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_E=100;
const int INF=1000000009;
struct edge{//�Ӷ���fromָ�򶥵�to��ȨֵΪcost�ı� 
	int from,to,cost;
};
edge es[MAX_E];//�߼� 
int d[MAX_E];//d[u]��u����Դ�����С���� 
int V,E;//VΪ��������EΪ����,������Ϊ1��2����������n
//���Ӷ���s�� ���ж���ľ��� 
int shortest_path(int s){
	for(int i=0;i<V;i++)d[i]=INF;
	//fill(d,d+V,INF); 
	d[s]=0;
	while(true){
		bool update=false;
		for(int i=0;i<E;i++){
			edge e=es[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
			if(!update)break;
		}
	} 
}
/***
�����ͼ�в����ڴ�s�ɴ�ĸ�Ȧ����ô���·���ᾭ��ͬһ���������Σ�Ҳ����˵����ྭ��|V|-1���ߣ�����ôwhile(true)
ѭ�����ִ��|V|-1�Ρ� 
���һ��ʼ�����еĶ���i,����d[i]��ʼ��Ϊ0������Լ������еĸ�Ȧ��
�����������true����ڸ�Ȧ 
*/ 
bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				if(i==V-1)return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&V,&E);
	for(int i=0;i<E;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		es[i].from=x;
		es[i].to=y;
		es[i].cost=z;
	} 
	int start,end;//������㣬�յ� 
	scanf("%d%d",&start,&end);
	int ans=shortest_path(start); 
	printf("%d\n",ans);
	return 0;
}
