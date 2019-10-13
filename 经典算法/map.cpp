#include<bits/stdc++.h>
using namespace std;

class my_compare_
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
/*bool my_compare_(const int &x,const int &y){
	return x>y;
}//²»¿ÉÒÔ£¬map<class_name,class_name,class_name> 
*/

int main(int argc, char *argv[])
{
    map<int, int, my_compare_> c;
    c.insert({pair<int, int>(1,10),pair<int, int>(2,20),pair<int, int>(3,30),pair<int, int>(4,40),pair<int, int>(5,50),pair<int, int>(6,60)});
    for(auto i : c)
    {
        cout<<"["<< i.first <<"] = " << i.second <<"  ";
    }
    cout << endl;
    return 0;
}
