/**
STL�������ֲ�ͬ�Ķ��ֲ����㷨��binary_search    lower_bound  upper_bound   equal_range.
�������õ�range����sorted��

binary_search��ͼ���������[first, last)��Ѱ��Ԫ��value�����[first, last)���еȼ���value��Ԫ�أ�
���᷵��true�����򷵻�false���������ز���λ�á�

lower_bound����ͼ���������[first,last)��Ѱ��Ԫ��value�����[first, last)���еȼ���value��Ԫ�أ�
lower_bound����һ��iteratorָ�����е�һ��Ԫ�ء����û��������Ԫ�ش��ڣ����㷵�ؼ���������Ԫ�ش��ڵĻ���
����ֵ�λ�á���ָ���һ����С��value��Ԫ�ء����value����[first, last)���κ�һ��Ԫ�أ��򷵻�last��

upper_bound����ͼ���������[first,last)��Ѱ��value�����ؿɰ���value�����һ�����ʵ�λ�á����value���ڣ�
lower_bound ���ص���ָ���Ԫ�ص�iterator�����֮��upper_bound������ô����������value�ɱ���������һ������λ�á�
���value���ڣ���ô�����ص�iterator��ָ��value����һ��λ�ã�����value����

equal_range�ķ���ֵ�����Ͻ����lower_bound��upper_bound���ߵķ���ֵ���䷵��ֵ��һ��iterator i �� j �� 
����i��value�ɰ���ĵ�һ��λ�ã�j����value�ɰ�������һ��λ�á��������ݳ���[i��j)�е�ÿ��Ԫ�ض��ȼ���value��
����[i, j)��[first, last)֮�з����������ʵ�һ����������䡣

�㷨lower_bound���ظ�range�ĵ�һ��iterator��
�㷨upper_bound���ظ�range��past-the-end iterator��
�㷨equal_range������pair����ʽ�����߶����ء�
*/
#include <algorithm>

#include <iostream>

#include <iterator>

#include <vector>

using namespace std;

int main()

{
    vector<int> v;
    vector<int>::iterator iter;
    pair<vector<int>::iterator, vector<int>::iterator> vecpair;
    for(int i = 1; i<= 20; i++) {

        v.push_back(i%6);

    }

    sort(v.begin(), v.end());

    cout << "array: " << endl << "  ";

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    cout << endl << endl;

 

 

    /*  lower_bound */

    cout << "lower_bound function, value = 3: " << endl;

    iter = lower_bound(v.begin(), v.end(), 3);

    cout << "  [first, iter] = ";

    copy(v.begin(), iter, ostream_iterator<int>(cout, " "));

    cout << endl;

    cout << "  [iter, last] = ";

    copy(iter, v.end(), ostream_iterator<int>(cout, " "));

    cout << endl << endl;

 

 

    /*  upper_bound */

    cout << "upper_bound function, value = 3: " << endl;

    iter = upper_bound(v.begin(), v.end(), 3);

    cout << "  [first, iter] = ";

    copy(v.begin(), iter, ostream_iterator<int>(cout, " "));

    cout << endl;

    cout << "  [iter, last] = ";

    copy(iter, v.end(), ostream_iterator<int>(cout, " "));

    cout << endl << endl;

 

 

    /*  equal_range */

    cout << "euqual_range function value = 3: " << endl;

    vecpair = equal_range(v.begin(), v.end(), 3);

 

 

    cout << " [vecpair->first, vecpair->second] = ";

    copy(vecpair.first, vecpair.second, ostream_iterator<int>(cout, " "));

    cout << endl << endl;

 

 

    /*  binary_search */

    cout << "binary_search function value = 3: " << endl;

    cout << "3 is " << (binary_search(v.begin(), v.end(), 3) ? "": "not ") << " in array" << endl;

    cout << endl;

 

 

    /*  binary_search */

    cout << "binary_search function value = 6: " << endl;

    cout << "6 is " << (binary_search(v.begin(), v.end(), 6) ? "": "not ") << " in array" << endl;

    cout << endl;

}

 

 


