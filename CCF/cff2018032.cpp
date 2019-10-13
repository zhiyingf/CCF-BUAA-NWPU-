#include<bits/stdc++.h>

using namespace std;

struct p{
    int order;
    int number;
}numbers[1005];
int a[1005];
bool cmp1(p a , p b)
{
    return a.number < b.number;
}

bool cmp2(p a , p b)
{
    return a.order < b.order;
}

int main()
{
    int n,l,t,temp;
    //scanf("%d%d%d",&n,&l,&t);
    cin>>n>>l>>t;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> numbers[i].number;
        a[i]=numbers[i].number;
        numbers[i].order = i;
    }
    sort(numbers , numbers + n , cmp1);
    for(int i = 0 ; i < n ; i++)
    {
        numbers[i].number = i;
    }
    sort(numbers , numbers + n , cmp2);
    for(int i=0;i<n;i++){
		temp=l-a[i];
		if(temp>=t)a[i]+=t;
		else{
			int x=(t-temp)%(2*l);
			a[i]=abs(l-x);}
	}
	sort(a,a+n);
	for(int i = 0 ; i < n ; i++)
    {
        cout << a[numbers[i].number] << " ";
    }
    cout << endl;
    return 0;
}

