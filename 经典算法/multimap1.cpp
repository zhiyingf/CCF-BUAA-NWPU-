#include<bits/stdc++.h>
using namespace std;
class sst{

public:

    int x;

    int y;

    //sst(int a, int b):x(a), y(b){}
    sst(int a,int b){
    	x=a;y=b;
	}
    friend bool operator<(const sst& a, const sst& b)

   {

    return a.x < b.x;       //����map��key��sst�е�x��

   }

};

 
/*
bool operator<(const sst& a, const sst& b)

{

    return a.x < b.x;       //����map��key��sst�е�x��

}*/

 

void map_test()     //����һ��unordered_map��������ǲ����Զ�����

{

    map<sst ,int> mp;

    //����

    for (int i = 1; i < 10; i++)

        mp[sst(i, i + 1)] = i * 5;

    

    mp.insert(make_pair(sst(2, 5), 50));                //��map���Ѿ���sst.x=2��������insert sst.x=2��ֵ�ͻ���ԡ�

    

    for (auto it = mp.begin(); it != mp.end(); it++)    //1-2-5  2-3-10  3-4-15  4-5-20  5-6-25  6-7-30  7-8-35  8-9-40  9-10-45

        cout<<it->first.x<<"-"<<it->first.y<<"-"<<it->second<<"  ";

    cout<<endl;

    

    //ʹ��

    cout<<mp[sst(2, 5)]<<endl;                          //10 ��map��sst.x = 2����(����y��û����)������valueֵ

    cout<<mp[sst(10, 11)]<<endl;                        //0  ��map��û��sst.x=10������������� mp[sst(10, 11)] = 0;

    

    for (auto it = mp.begin(); it != mp.end(); it++)    //1-2-5  2-3-10  3-4-15  4-5-20  5-6-25  6-7-30  7-8-35  8-9-40  9-10-45  10-11-0

        cout<<it->first.x<<"-"<<it->first.y<<"-"<<it->second<<"  ";

    cout<<endl;

    

    //ɾ��

    mp.erase(sst(2, 0));

    mp.erase(mp.begin());

 

    for (auto it : mp)                                  //3-4-15  4-5-20  5-6-25  6-7-30  7-8-35  8-9-40  9-10-45  10-11-0

        cout<<it.first.x<<"-"<<it.first.y<<"-"<<it.second<<"  ";

    cout<<endl;

 

    //����

    cout<<mp.lower_bound(sst(5, 5))->second<<endl;     //25 ���ص�һ��sst.x�� 5 ���ڵ��ڵ� ������

    cout<<mp.upper_bound(sst(5, 5))->second<<endl;     //30 ���ص�һ��sst.x�� 5 ���� �� ������

 

    auto ret = mp.equal_range(sst(6, 6));              //��key����25�ĵ�������Χ��[ret.first, ret.second)

    cout<<ret.first->first.x<<" "<<ret.first->second<<endl;     //6 30

    cout<<ret.second->first.x<<" "<<ret.second->second<<endl;   //7 35

 

    mp.size();

    cout<<mp.find(sst(3, 33))->first.y<<endl;   //4 �ҵ���sst.x = 3�ĵ���������sst.y�޹�

    mp.empty();

    mp.clear();

}
///////////////////////////

class msst{

public:

    int x;

    int y;

    msst(int a, int b):x(a), y(b){}
    friend bool operator<(const msst& a, const msst& b)

   {

    return a.x < b.x;       //����map��key��sst�е�x��

   }

};

 

/*bool operator<(const msst& a, const msst& b)

{

    return a.x < b.x;       //����map��key��sst�е�x��

}*/

 

 

void multimap_test()

{

    multimap<msst ,int> mp;

    //����

    for (int i = 1; i < 10; i++)

        mp.insert(make_pair(msst(i, i + 1), i * 5));

    

    mp.insert(make_pair(msst(2, 5), 50));               //��multimap�оͿ����ж�� sst.x=2 ���

    mp.insert(make_pair(msst(6, 6), 6));

    

    for (auto it = mp.begin(); it != mp.end(); it++)    //1-2-5  2-3-10  2-5-50  3-4-15  4-5-20  5-6-25  6-7-30  6-6-6  7-8-35  8-9-40  9-10-45

        cout<<it->first.x<<"-"<<it->first.y<<"-"<<it->second<<"  ";

    cout<<endl;

    

    //ʹ��

    //cout<<mp[msst(2, 5)]<<endl;                          //multimap���ܹ�������ȡ

    

    //ɾ��

    mp.erase(msst(2, 0));               //ɾ������sst.x = 2����

    mp.erase(mp.begin());               //mp.erase(mp.begin() + 4)�����ǲ��е�

    

    for (auto it : mp)                                  //3-4-15  4-5-20  5-6-25  6-7-30  6-6-6  7-8-35  8-9-40  9-10-45

        cout<<it.first.x<<"-"<<it.first.y<<"-"<<it.second<<"  ";

    cout<<endl;

    

    //����

    cout<<mp.lower_bound(msst(6, 5))->second<<endl;     //30 ���ص�һ��sst.x�� 6 ���ڵ��ڵ� ������

    cout<<mp.upper_bound(msst(6, 5))->second<<endl;     //35 ���ص�һ��sst.x�� 6 ���� �� ������

    

    auto ret = mp.equal_range(msst(6, 6));              //��key����25�ĵ�������Χ��[ret.first, ret.second)

    cout<<ret.first->first.x<<" "<<ret.first->second<<endl;     //6 30

    cout<<ret.second->first.x<<" "<<ret.second->second<<endl;   //7 35

    

    mp.size();

    cout<<mp.find(msst(6, 33))->first.y<<endl;   //7 �ҵ���sst.x = 6�ĵ�һ������������sst.y�޹�

    mp.empty();

    mp.clear();

}
/////////////////////
int main(){
	map_test();
	return 0;
}

