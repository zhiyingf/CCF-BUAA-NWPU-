#include <stdio.h>
struct Next
{
	int next[2];
	bool mark;
}go[8];
void inti()
{	
	go[0].next[0]=-1;
	go[0].next[1]=1;
	go[1].next[0]=-1;
	go[1].next[1]=-0;
	go[2].next[0]=-1;
	go[2].next[1]=-1;
	go[3].next[0]=0;
	go[3].next[1]=-1;
	go[4].next[0]=1;
	go[4].next[1]=-1;
	go[5].next[0]=1;
	go[5].next[1]=0;
	go[6].next[0]=1;
	go[6].next[1]=1;
	go[7].next[0]=0;
	go[7].next[1]=1;
	int i;
	for(i=0;i<8;i++)
	{
		go[i].mark=false;
	}

}
int buf[19][19];
int cnt=1;
int startx, starty;

void cmp(int x,int y)
{
	int i,j;
	int a,b;
	int fin;
	startx=x, starty=y;
	if(cnt==1&&buf[x][y]!=0)//每个方向遍历
	{
		for(i=0;i<8;i++)
		{
			if(x+go[i].next[0]>=0&&x+go[i].next[0]<=18&&y+go[i].next[1]>=0&&y+go[i].next[1]<=18)
			{
				if(buf[x][y]==buf[x+go[i].next[0]][y+go[i].next[1]])
				{	
					fin=fin<(x+go[i].next[0])+19*(y+go[i].next[1])?fin:(x+go[i].next[0])+19*(y+go[i].next[1]);
					cnt++;
					go[i].mark=true;
					x+=go[i].next[0];y+=go[i].next[1];
					cmp(x,y);
				}
				else go[i].mark=false;
			}
		}
	}
	else //只能朝一个方向，且这个方向的mark为true；
	{
		for(j=0;j<8;j++)
		{
			if(go[j].mark==true)
			{
				if(x+go[i].next[0]>=0&&x+go[i].next[0]<=18&&y+go[i].next[1]>=0&&y+go[i].next[1]<=18)
				{
					if(buf[x][y]==buf[x+go[i].next[0]][y+go[i].next[1]])
					{
						cnt++;
						fin=fin<(x+go[i].next[0])+19*(y+go[i].next[1])?fin:(x+go[i].next[0])+19*(y+go[i].next[1]);
						x+=go[i].next[0];y+=go[i].next[1];
						if(cnt==5)	
						{
							printf("%d:%d,%d,",buf[x][y],fin%19+1,fin/19+1);
							return;
						}
						cmp(x,y);
					}
				}
				else
				{
					go[i].mark=false;
					cnt=1;
				}

			}
			else
			{	
				cnt=1;
				go[i].mark=false;
				x=startx;
				y=starty;
			}
		}
	}
}
int main()
{
	int i,j;
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
				scanf("%d",&buf[i][j]);
		}
	}
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			cmp(i,j);
		}
	}
	return 0;
}