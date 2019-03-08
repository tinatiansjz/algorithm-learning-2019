// f[i][s]表示从前i个物品中选出若干个，属性奇偶性是s的情况下能达到的最高价值。
// f[i][s] = max(f[i-1][s], max{f[i-1][t] + v[i], 其中t=0, 1, ... 2^m-1 且 t|st[i] == s})
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define id(x) (x&1)
using namespace std;
const int maxn = 1000+5;
const int width = 1030;
int n, m, T;
int dp[2][width];
int s[maxn]; // state
int v[maxn]; // value
void init(){
    memset(dp, 0, sizeof(dp));
    memset(s, 0, sizeof(s));
    memset(v, 0, sizeof(v));
}
int solve(){
    dp[1][s[1]] = v[1];
    for(int i = 1; i < n; i++){
        dp[id(i+1)][s[i+1]] = v[i+1];
        for(int j = 0; j < (1<<m); j++){
            if(dp[id(i)][j] == 0) continue;
            dp[id(i+1)][j] = max(dp[id(i+1)][j], dp[id(i)][j]);
            dp[id(i+1)][j^s[i+1]] = max(dp[id(i+1)][j^s[i+1]], dp[id(i)][j]+v[i+1]);
        }
        for(int j = 0; j < (1<<m); j++) dp[id(i)][j] = 0;
    }
    return dp[id(n)][(1<<m)-1];
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--){
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            int cnt; scanf("%d%d", &v[i], &cnt);
            for(int j = 0; j < cnt; j++){
                int tmp; scanf("%d", &tmp);
                s[i] |= 1<<(tmp-1);
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}