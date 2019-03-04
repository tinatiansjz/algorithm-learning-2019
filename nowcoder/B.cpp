// dp
// dp[i][j]: 走到第i个，分数为j的方案数
#include <iostream>
#include <cstdio>
#include <cstring>
#define add(x) (x+200000)
using namespace std;
const int maxn = 300+5;
const int maxi = 4e5+5;
const int MOD = 1e8+7;
int a[maxn];
int dp[2][maxi];
int main(){
    // freopen("in.txt", "r", stdin);
    int N; scanf("%d", &N);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    if(a[0] == 666) dp[0][add(a[0])] = 0;
    else dp[0][add(a[0])] = 1;
    dp[0][add(0)] = 1;
    for(int i = 1; i < N; i++){
        int up = 666*i;
        for(int j = -up; j <= up; j++){
            int tmp = dp[(i-1)&1][add(j)];
            if(tmp == 0) continue;
            if(-j != 666)
                dp[i&1][add(-j)] = (dp[i&1][add(-j)]+tmp)%MOD;
            if(j+a[i] != 666)
                dp[i&1][add(j+a[i])] = (dp[i&1][add(j+a[i])]+tmp)%MOD;
            // printf("Hello\n");
        }
        for(int j = -up; j <= up; j++) dp[i&1^1][add(j)] = 0;
    }
    cout << dp[(N-1)&1][add(-666)] << endl;
    return 0;
}