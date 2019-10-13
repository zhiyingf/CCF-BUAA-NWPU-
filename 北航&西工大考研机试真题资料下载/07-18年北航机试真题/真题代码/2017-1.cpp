#include <stdio.h>
#include <algorithm>
using namespace std;
struct Num
{
	int num;
	int idx;
	bool operator < (const Num &A) const
	{
		return num<A.num;
	}
}buf[100];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&buf[i].num);
		buf[i].idx=i;
	}
	sort(buf+1,buf+1+n);
	if(n%2==1) 
	{
		printf("%d %d\n",buf[n/2+1].num,buf[n/2+1].idx);
	}
	else
	{
		printf("%d %d\n",buf[n/2].num,buf[n/2].idx);
		printf("%d %d",buf[n/2+1].num,buf[n/2+1].idx);

	}
	return 0;
}
