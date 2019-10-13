#include <stdio.h>
#include <algorithm>
using namespace std;
struct Win
{
	int id;
	int zxx,zxy,ysx,ysy;
	int idx;
	bool mark;
	bool operator < (const Win &A) const
	{
		return idx<A.idx;
	}
}win[100];
Win tmp[100];
bool scope(int x,int y,int i)
{
	if(x>=win[i].zxx&&y>=win[i].zxy&&x<=win[i].ysx&&y<=win[i].ysy)
		return true;
	return false;
}
struct Click
{
	int x;
	int y;
}click[100];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d",&win[i].id,&win[i].zxx,&win[i].zxy,&win[i].ysx,&win[i].ysy);
		win[i].idx=i;
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&click[i].x,&click[i].y);
	}
	int j=0;
	for(i=0;i<m;i++)
	{
		int k=0;
		for(j=0;j<n;j++)
		{
			win[j].mark=false;
			tmp[j].mark=false;
			tmp[j].id='\0';
		}
		for(j=0;j<n;j++)
		{
			win[j].mark=scope(click[i].x,click[i].y,j);
			if(win[j].mark)	
			{
				tmp[k].id=win[j].id;
				tmp[k].idx=win[j].idx;
				k++;
			}
		}
		sort(tmp,tmp+k);
		int m;
		for(m=0;m<n;m++)
		{
			if(win[m].id==tmp[0].id)
			{
				win[m].idx=0;

			}
			else win[m].idx++;
		}
	}
	sort(win,win+n);
	for(m=0;m<n;m++)
	{
		printf("%d ",win[m].id);
	}
	return 0;
}