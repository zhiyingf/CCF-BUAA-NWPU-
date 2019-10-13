#include <bits/stdc++.h>
using namespace std;
typedef vector <string> vs; 
const int N=1e4+7;
struct node { // 消息类型
    int x,y;   // x->y  flag=1 是S  
    bool flag;
};
int s[N],r[N]; // S[x]=y  表示x 第一个消息是Sy
node msg[N][10];  int num[N];  // msg 以倒序方式存储每一个人所有消息
                              // num[i] 表示第i个人消息数量
queue <node>  q;   // 建立消息队列
int n;
vs split (string str, const char flag=' ') { // 分割字符串
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
void get_in (int k) {  // 所有人的第一个消息进队列
    if (num[k]) {  // 没有元素不进行任何操作
                   // 编程还重要的是构造统一的接口,简化代码
        q.push(msg[k][num[k]]);
        num[k]--;
    }
}
int main ()
{
    int T; cin>>T>>n; getchar();
    while (T--) {
        memset (s,-1,sizeof(s));// 初始化很重要
        memset (r,-1,sizeof(r));
        memset (msg,0,sizeof(msg));
        memset (num,0,sizeof(num));
        for (int i=0;i<n;i++) {
            string str; getline(cin,str);
            vs sv=split(str);
            num[i]=sv.size();
            for (int j=0;j<sv.size();j++) {  // 对消息的处理
                int k=num[i]-j;
                msg[i][k].x=i;
                msg[i][k].y=to_int(sv[j].substr(1));
                if (sv[j][0]=='S') msg[i][k].flag=1;
            }
        }
        for (int i=0;i<n;i++)  get_in(i);  // 开始所有人的第一个进入队列
        int sum=0;
        while (!q.empty()) {
            node tmp=q.front(); q.pop(); 
            bool isok=0;
            int x=tmp.x,y=tmp.y;
            if (tmp.flag) {  // 若这个消息此时有对应 则消去 对应是指[ s[x]=y; r[y]=x; ]
                if (r[y]==x) { isok=1; r[y]=-1; get_in(x); get_in(y); }  // 消去的时候两人下一个消息进入队列
                else         s[x]=y;// 不能消去 更新
            }
            else {
                if (s[y]==x) {isok=1; s[y]=-1; get_in(x); get_in(y); }
                else         r[x]=y;
            }
            if (isok) sum++;  // sum 表示为被消去的消息数量
            else      sum--;
        }
        if (sum==0) cout<<"0\n";
        else        cout<<"1\n";
    }
    return 0;
}
