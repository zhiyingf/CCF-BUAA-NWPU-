#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int main()
{
    int ans[1000],num=0;
    cin>>n;
    while(n){//快速幂：十进制转二进制，先得低位，后得高位 
        if(n&1) ans[num]=1;
        else ans[num]=0;
        n=n>>1;
        num++;
    }
    for(int i=num-1;i>=0;i--){
        /*
        if(i==num-1) printf("%d",ans[i]);
        else printf("%d",ans[i]);
		*/
		printf("%d",ans[i]);
    }
    cout<<endl;
    return 0;
}
