// 0-1 Package
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
int v[maxn]; // value
int w[maxn]; // weight
int dp[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        int N, W; scanf("%d%d", &N, &W);
        for(int i = 0; i < N; i++) scanf("%d", &v[i]);
        for(int i = 0; i < N; i++) scanf("%d", &w[i]);
        for(int i = 0; i < N; i++)
            for(int j = W; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        int ans = -1;
        for(int i = 0; i <= W; i++) ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}