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

    return a.x < b.x;       //代表map中key是sst中的x。

   }

};

 
/*
bool operator<(const sst& a, const sst& b)

{

    return a.x < b.x;       //代表map中key是sst中的x。

}*/

 

void map_test()     //还有一种unordered_map。区别就是不会自动排序。

{

    map<sst ,int> mp;

    //插入

    for (int i = 1; i < 10; i++)

        mp[sst(i, i + 1)] = i * 5;

    

    mp.insert(make_pair(sst(2, 5), 50));                //当map中已经有sst.x=2的项。如果再insert sst.x=2的值就会忽略。

    

    for (auto it = mp.begin(); it != mp.end(); it++)    //1-2-5  2-3-10  3-4-15  4-5-20  5-6-25  6-7-30  7-8-35  8-9-40  9-10-45

        cout<<it->first.x<<"-"<<it->first.y<<"-"<<it->second<<"  ";

    cout<<endl;

    

    //使用

    cout<<mp[sst(2, 5)]<<endl;                          //10 当map有sst.x = 2的项(不管y对没对上)，返回value值

    cout<<mp[sst(10, 11)]<<endl;                        //0  当map中没有sst.x=10的项，这个语句会添加 mp[sst(10, 11)] = 0;

    

    for (auto it = mp.begin(); it != mp.end(); it++)    //1-2-5  2-3-10  3-4-15  4-5-20  5-6-25  6-7-30  7-8-35  8-9-40  9-10-45  10-11-0

        cout<<it->first.x<<"-"<<it->first.y<<"-"<<it->second<<"  ";

    cout<<endl;

    

    //删除

    mp.erase(sst(2, 0));

    mp.erase(mp.begin());

 

    for (auto it : mp)                                  //3-4-15  4-5-20  5-6-25  6-7-30  7-8-35  8-9-40  9-10-45  10-11-0

        cout<<it.first.x<<"-"<<it.first.y<<"-"<<it.second<<"  ";

    cout<<endl;

 

    //其他

    cout<<mp.lower_bound(sst(5, 5))->second<<endl;     //25 返回第一个sst.x比 5 大于等于的 迭代器

    cout<<mp.upper_bound(sst(5, 5))->second<<endl;     //30 返回第一个sst.x比 5 大于 的 迭代器

 

    auto ret = mp.equal_range(sst(6, 6));              //找key等于25的迭代器范围。[ret.first, ret.second)

    cout<<ret.first->first.x<<" "<<ret.first->second<<endl;     //6 30

    cout<<ret.second->first.x<<" "<<ret.second->second<<endl;   //7 35

 

    mp.size();

    cout<<mp.find(sst(3, 33))->first.y<<endl;   //4 找的是sst.x = 3的迭代器，和sst.y无关

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

    return a.x < b.x;       //代表map中key是sst中的x。

   }

};

 

/*bool operator<(const msst& a, const msst& b)

{

    return a.x < b.x;       //代表map中key是sst中的x。

}*/

 

 

void multimap_test()

{

    multimap<msst ,int> mp;

    //插入

    for (int i = 1; i < 10; i++)

        mp.insert(make_pair(msst(i, i + 1), i * 5));

    

    mp.insert(make_pair(msst(2, 5), 50));               //在multimap中就可以有多个 sst.x=2 的项。

    mp.insert(make_pair(msst(6, 6), 6));

    

    for (auto it = mp.begin(); it != mp.end(); it++)    //1-2-5  2-3-10  2-5-50  3-4-15  4-5-20  5-6-25  6-7-30  6-6-6  7-8-35  8-9-40  9-10-45

        cout<<it->first.x<<"-"<<it->first.y<<"-"<<it->second<<"  ";

    cout<<endl;

    

    //使用

    //cout<<mp[msst(2, 5)]<<endl;                          //multimap不能够这样读取

    

    //删除

    mp.erase(msst(2, 0));               //删除所有sst.x = 2的项

    mp.erase(mp.begin());               //mp.erase(mp.begin() + 4)这样是不行的

    

    for (auto it : mp)                                  //3-4-15  4-5-20  5-6-25  6-7-30  6-6-6  7-8-35  8-9-40  9-10-45

        cout<<it.first.x<<"-"<<it.first.y<<"-"<<it.second<<"  ";

    cout<<endl;

    

    //其他

    cout<<mp.lower_bound(msst(6, 5))->second<<endl;     //30 返回第一个sst.x比 6 大于等于的 迭代器

    cout<<mp.upper_bound(msst(6, 5))->second<<endl;     //35 返回第一个sst.x比 6 大于 的 迭代器

    

    auto ret = mp.equal_range(msst(6, 6));              //找key等于25的迭代器范围。[ret.first, ret.second)

    cout<<ret.first->first.x<<" "<<ret.first->second<<endl;     //6 30

    cout<<ret.second->first.x<<" "<<ret.second->second<<endl;   //7 35

    

    mp.size();

    cout<<mp.find(msst(6, 33))->first.y<<endl;   //7 找的是sst.x = 6的第一个迭代器，和sst.y无关

    mp.empty();

    mp.clear();

}
/////////////////////
int main(){
	map_test();
	return 0;
}

