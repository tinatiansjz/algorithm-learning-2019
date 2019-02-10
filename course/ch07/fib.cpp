#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1010;
int dp[maxn];
int count = 1;
int fib(int n){
    dp[1] = dp[2] = 1;
    cout << count++ << "计算出Fib(1)=1\n";
    cout << count++ << "计算出Fib(2)=1\n";
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        printf("%d计算出Fib(%d)=%d\n", count++, i, dp[i]);
    }
    return dp[n];
}
int main(){
    fib(5);
}
