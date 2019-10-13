#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool cmp(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||c=='_'||(c>='0'&&c<='9'))
		return true;
	return false;
}
int main(){
	int i=0,j,tol,k;
    char s1[1000],s2[1000],aim[1000][20],tmp[20];
	cin.getline(s1,1000);
	cin.getline(s2,1000);
	tol=0,k=0;
	int len1=strlen(s1),len2=strlen(s2),lian=0;
	while(s1[i]==' ')	i++;
	while(cmp(s1[i]))	i++;
	while(s1[i]==' ')	i++;
	j=i;
    for(i=j;i<len1;i++){
		if(s1[i]==' ')
		{
			while(s1[i]==' ')
				i++;
			i--;
		}
        else if(s1[i]=='*')continue;
        else if(cmp(s1[i]))
			aim[tol][k++]=s1[i];
		else if(s1[i]==','||s1[i]==';'||s1[i]=='=')
		{
			aim[tol][k]='\0',tol++,k=0;
		}
		else if(s1[i]=='[')
		{
			while(s1[i]!=']')i++;
			i--;
		}
	}
//	for(i=0;i<tol;i++)printf("%s\n",aim[i]);
int p=0,flag=0;
for(i=0;i<len2;i++)
{
	if(cmp(s2[i]))
	{
		tmp[p++]=s2[i];
	}
	else if(s2[i]=='[')
	{
        while(s2[i]==']')	i++;
		i--;
	}
	else if(s2[i]=='='||s2[i]=='+'||s2[i]=='-'||s2[i]=='*'||s2[i]=='/'||s2[i]==','||s2[i]==';')
	{
		if(s2[i+1]>='0'&&s2[i+1]<='9'){while(s2[i+1]>='0'&&s2[i+1]<='9')i++;i++;}
        tmp[p]='\0';
             for(j=0;j<tol;j++){
				 if(strcmp(tmp,aim[j])==0)
				 {
					 flag=1;
				 }
			 }
			 if(!flag)printf("%s ",tmp);
			 flag=0;
			 p=0;memset(tmp,'\0',sizeof(tmp));
		}
	}
	printf("\n");
	return 0;
}
