// https://codeforces.com/blog/entry/67388
// s = 2^x*3^y (y<=1)
// 位移加速运算，否则会TLE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define r(x) x&1
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
// const int maxn = 1e6+5;
const int maxx = 25;
ll dp[2][maxx][2];
int n;
inline int f(int x, int y){
    int tmp = (1<<x);
    if(y) tmp *= 3;
    return n/tmp;
}
void debug(int i, int x){
    cout << "i: " << i << endl;
    for(int m = 0; m <= x; m++)
        cout << dp[r(i)][m][0] << " " << dp[i][m][1] << endl;
}
int main(){
    // freopen("in.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    cin >> n;
    int p = 0;
    while((1<<p) <= n) p++;
    p--;
    dp[1][p][0] = 1;
    if((1<<(p-1))*3 <= n)
        dp[1][p-1][1] = 1;
    // dp[i][x][y] = dp[i][x][y]+dp[i-1][x][y]*(f(x,y)-i+1);
    // dp[i][x-1][y] = dp[i][x-1][y]+dp[i-1][x][y]*(f(x-1,y)-f(x,y))
    // dp[i][x][y-1] = dp[i][x][y-1]+dp[i-1][x][y]*(f(x,y-1)-f(x,y))
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= p; j++) dp[r(i)][j][0] = dp[r(i)][j][1] = 0;
        for(int j = 0; j <= p; j++){
            dp[r(i)][j][0] = (dp[r(i)][j][0]+dp[r(i-1)][j][0]*(f(j,0)-i+1)%MOD)%MOD;
            dp[r(i)][j][1] = (dp[r(i)][j][1]+dp[r(i-1)][j][1]*(f(j,1)-i+1)%MOD)%MOD;
            if(j >= 1){
                dp[r(i)][j-1][0] = (dp[r(i)][j-1][0]+dp[r(i-1)][j][0]*(f(j-1,0)-f(j,0))%MOD)%MOD;
                dp[r(i)][j-1][1] = (dp[r(i)][j-1][1]+dp[r(i-1)][j][1]*(f(j-1,1)-f(j,1))%MOD)%MOD;
            }
            dp[r(i)][j][0] = (dp[r(i)][j][0]+dp[r(i-1)][j][1]*(f(j,0)-f(j,1))%MOD)%MOD;
        }
        // debug(r(i), x);
    }
    cout << dp[r(n)][0][0] << endl;
    return 0;
}