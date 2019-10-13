#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int h,m,mm,ah,am,amm;
	while(n--){
		ah=0;am=0;amm=0;
		for(int i=0;i<3;i++){
			cin>>h>>m>>mm;
		    ah+=h;am+=m;amm+=mm; 
		}
		cout<<ah/3<<" "<<am/3<<" "<<amm/3<<endl;
	} 
	return 0;
	
} 
