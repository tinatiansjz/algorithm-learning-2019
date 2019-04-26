#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100+5;
const int maxv = 1e4+5;
double w[maxn]; // weight
int v[maxn]; // value
double dp[maxv]; // 偷到 a certain value下的最大不被抓概率
inline void init(){
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--){
        init();
        double P; int N;
        scanf("%lf%d", &P, &N);
        int tot = 0;
        P = 1-P; // //不被抓的概率
        for(int i = 0; i < N; i++){
            scanf("%d%lf", &v[i], &w[i]);
            w[i] = 1.0 - w[i];
            tot += v[i];
        }
        for(int i = 0; i < N; i++)
            for(int j = tot; j >= v[i]; j--)
                dp[j] = dp[j] > dp[j-v[i]]*w[i] ? dp[j] : dp[j-v[i]]*w[i];
        for(int i = tot; i >= 0; i--){
            if(dp[i] < P) continue;
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}