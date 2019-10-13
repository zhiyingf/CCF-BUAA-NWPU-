#include <bits/stdc++.h>
using namespace std;
typedef vector <string> vs; 
const int N=1e4+7;
struct node { // ��Ϣ����
    int x,y;   // x->y  flag=1 ��S  
    bool flag;
};
int s[N],r[N]; // S[x]=y  ��ʾx ��һ����Ϣ��Sy
node msg[N][10];  int num[N];  // msg �Ե���ʽ�洢ÿһ����������Ϣ
                              // num[i] ��ʾ��i������Ϣ����
queue <node>  q;   // ������Ϣ����
int n;
vs split (string str, const char flag=' ') { // �ָ��ַ���
    istringstream iss(str);
    vs ans;
    while (getline(iss,str,flag))
        if (str.size())
            ans.push_back(str);
    return ans;
}
int to_int (string str) {  // string->int
    int ans=0;
    for (int i=0;i<str.size();i++)
        ans=ans*10+str[i]-'0';
    return ans;
}
void get_in (int k) {  // �����˵ĵ�һ����Ϣ������
    if (num[k]) {  // û��Ԫ�ز������κβ���
                   // ��̻���Ҫ���ǹ���ͳһ�Ľӿ�,�򻯴���
        q.push(msg[k][num[k]]);
        num[k]--;
    }
}
int main ()
{
    int T; cin>>T>>n; getchar();
    while (T--) {
        memset (s,-1,sizeof(s));// ��ʼ������Ҫ
        memset (r,-1,sizeof(r));
        memset (msg,0,sizeof(msg));
        memset (num,0,sizeof(num));
        for (int i=0;i<n;i++) {
            string str; getline(cin,str);
            vs sv=split(str);
            num[i]=sv.size();
            for (int j=0;j<sv.size();j++) {  // ����Ϣ�Ĵ���
                int k=num[i]-j;
                msg[i][k].x=i;
                msg[i][k].y=to_int(sv[j].substr(1));
                if (sv[j][0]=='S') msg[i][k].flag=1;
            }
        }
        for (int i=0;i<n;i++)  get_in(i);  // ��ʼ�����˵ĵ�һ���������
        int sum=0;
        while (!q.empty()) {
            node tmp=q.front(); q.pop(); 
            bool isok=0;
            int x=tmp.x,y=tmp.y;
            if (tmp.flag) {  // �������Ϣ��ʱ�ж�Ӧ ����ȥ ��Ӧ��ָ[ s[x]=y; r[y]=x; ]
                if (r[y]==x) { isok=1; r[y]=-1; get_in(x); get_in(y); }  // ��ȥ��ʱ��������һ����Ϣ�������
                else         s[x]=y;// ������ȥ ����
            }
            else {
                if (s[y]==x) {isok=1; s[y]=-1; get_in(x); get_in(y); }
                else         r[x]=y;
            }
            if (isok) sum++;  // sum ��ʾΪ����ȥ����Ϣ����
            else      sum--;
        }
        if (sum==0) cout<<"0\n";
        else        cout<<"1\n";
    }
    return 0;
}
