
/* CCF201612-4 压缩编码 */

#include <iostream>

#include <cstring>

using namespace std;

const int INT_MAX2 = 0x7F7F7F7F;

const int N = 1000;

 

int v[N+1];

int sum[N+1];

int dp[N+1][N+1];

int p[N+1][N+1];

 

int main()

{

    int n;
    // 变量初始化：置为最大值

    memset(dp, INT_MAX2, sizeof(dp));
    // 输入数据

    cin >> n;

    sum[0] = 0;

    for(int i=1; i<=n; i++) {

        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
        dp[i][i] = 0;
        p[i][i] = i;
    }
    
    // DP计算

    for(int len=2; len<=n; len++)

        for(int i=1; i+len-1<=n; i++) {

            int j = i + len - 1;

            for(int k=p[i][j-1]; k<=p[i+1][j]; k++) {

                int val = dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1];

                if(dp[i][j]>val) {

                    dp[i][j] = val;

                    p[i][j] = k;

                }

            }

        }

 

    // 输出结果

    cout << dp[1][n] << endl;

 

    return 0;

}

