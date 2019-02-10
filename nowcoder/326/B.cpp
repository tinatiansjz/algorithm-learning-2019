// https://ac.nowcoder.com/acm/contest/326#question
// 2019/1/3 19:49
// dp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5010;
const int maxa = 60;
const int mod = 1e9 + 7;
long long dp[maxn][2][maxa];
void init(){
    memset(dp, 0, sizeof(dp));
    dp[1][0][1] = 5; dp[1][1][1] = 21;
}
void debug(int N, int A, int B){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= A; j++)
            cout << dp[i][0][j] << "\t";
        cout << endl;
    }
    cout << endl;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= B; j++)
            cout << dp[i][1][j] << "\t";
        cout << endl;
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T; cin >> T;
    while(T--){
        init();
        int N, A, B;
        scanf("%d%d%d", &N, &A, &B);
        for(int i = 2; i <= N; i++){
            // 0: vowel
            for(int j = 2; j <= A; j++)
                dp[i][0][j] = (dp[i][0][j] + dp[i-1][0][j-1]*5)%mod;
            // 1: consonant
            for(int j = 2; j <= B; j++)
                dp[i][1][j] = (dp[i][1][j] + dp[i-1][1][j-1]*21)%mod;
            // dp[i][0][1]
            for(int j = 1; j <= B; j++)
                dp[i][0][1] = (dp[i][0][1] + dp[i-1][1][j]*5)%mod;
            // dp[i][1][1]
            for(int j = 1; j <= A; j++)
                dp[i][1][1] = (dp[i][1][1] + dp[i-1][0][j]*21)%mod;
        }
        // debug(2, 2, 2);
        long long ans = 0;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= i && j <= A; j++)
                ans = (ans+dp[i][0][j])%mod;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= i && j <= B; j++)
                ans = (ans+dp[i][1][j])%mod;
        cout << ans << endl;
    }
    return 0;
}