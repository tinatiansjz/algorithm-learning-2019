//整数拆分问题
//dp (dynamic programming) top-down
//2018/11/28    10:47
/* f(n, m) = 1                          n=1, m=1
 *         = f(n, n)                    n<m
 *         = 1+f(n, n-1)                n=m
 *         = f(n, m-1)+f(n-m, m)        n>m>1
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1010;
long long dp[maxn][maxn];
long long partition(int n, int m){
    if(n == 1 || m == 1){dp[n][m] = 1; return 1;}
    if(n < m){
        dp[n][n] = dp[n][n]?dp[n][n]:partitionN(n, n);
        return dp[n][n];
    }else if(n == m){
        dp[n][m] = dp[n][n-1]?1+dp[n][n-1]:partition(n, n-1);
        return dp[n][m];
    }else {
        dp[n][m] = dp[n-m][m]?(dp[n-m][m]):partition(n-m, m);
        dp[n][m] += dp[n][m-1]?(dp[n][m-1]):partiton(n, m-1);
        return dp[n][m];
    }
}
int main(){
    return 0;
}
