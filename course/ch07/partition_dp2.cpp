//整数拆分问题
//dp (dynamic programming) bottom-up
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
long long dp[maxn];
long long partition(int n, int m){//make sure that m <= n
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i; j++){
            if(j == 1 || i == 1){dp[i][j] = 1;}
            else{
                if(j == i) dp[i][j] = w[i][j-1]+1;
                else if((i-j)<j){
                    dp[i][j] = dp[i-j][i-j] + dp[i][j-1];
                }else{
                    dp[i][j] = dp[i-j][j] + dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m];
}
