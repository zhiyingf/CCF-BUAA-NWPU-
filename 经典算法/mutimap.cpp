#include <iostream>
#include <string>
#include <map>
using namespace std;
  
int main()
{
    multimap<string,int> m_map;
    string s("中国"),s1("美国");
    m_map.insert(make_pair(s,50));
    m_map.insert(make_pair(s,55));
    m_map.insert(make_pair(s,60));
    m_map.insert(make_pair(s1,30));
    m_map.insert(make_pair(s1,20));
    m_map.insert(make_pair(s1,10));
    //方式1
    int k;
    multimap<string,int>::iterator m;
    m = m_map.find(s);
    for(k = 0;k != m_map.count(s);k++,m++)
        cout<<m->first<<"--"<<m->second<<endl;
    //方式2
    multimap<string,int>::iterator beg,end;
    beg = m_map.lower_bound(s1);
    end = m_map.upper_bound(s1);
    for(m = beg;m != end;m++)
        cout<<m->first<<"--"<<m->second<<endl;
    //方式3
    beg = m_map.equal_range(s).first;
    end = m_map.equal_range(s).second;
    for(m = beg;m != end;m++)
        cout<<m->first<<"--"<<m->second<<endl;
    //方式4
	beg = m_map.lower_bound(s);
	end = m_map.upper_bound(s);
	for(m = beg;m != end;m++)
        cout<<m->first<<"--"<<m->second<<endl;
		 
    return 0;
}

