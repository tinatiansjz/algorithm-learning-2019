// 2019/02/17 11:32
// Domino coverage problem 骨牌覆盖问题
// http://hihocoder.com/problemset/problem/1162
// refer to: HDU 1992
// 将矩形区域调整为N*K
// 从上往下一行一行地铺，当前处理行只会受到上一行的影响
// 0表示不占用下一行的位置(0一定为偶数个），1表示第i个位置会占用下一行（即砖是竖着放的）
// dp[i][cur]表示处理完前i行，第i行状态为cur的方法数，cur为01序列的十进制表示
// 根据s用dfs构造出一个可行状态nex，那么dp[i+1][nex] += dp[i][cur]
// dp (scrolling array)
// TLE 此方法可取，复杂度太大
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int K, N;
const int MOD = 12357;
const int maxn = 1e8+5;
const int maxk = 300;// 2^k
ll dp[2][maxk];
void dfs(int r, int c, int cur, int nex){
    //当前行 当前列 当前状态 可转移状态
    //已知r行状态cur，构造r+1行状态nex
    if(c >= K){
        // cout << "nex: " << nex << " cur: " << cur << endl;
        dp[(r+1)%2][nex] = (dp[(r+1)%2][nex]+dp[r%2][cur]%MOD)%MOD;
        // printf("dp[%d][%d] = %lld\n", (r+1)%2, nex, dp[(r+1)%2][nex]);
        return;
    }
    if(!(cur & (1<<c))){// cur[c] == 0
        dfs(r, c+1, cur, nex|(1<<c));// nex[c] = 1,即竖着放
        if(c <= K-2 && !(cur & 1<<(c+1)))// cur[c] == 0 && cur[c+1] == 0
            dfs(r, c+2, cur, nex);// nex[c],nex[c+1]可以横铺一个
    }else{
        dfs(r, c+1, cur, nex);// nex[c]已被上一行占用，直接跳过
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    cin >> K >> N;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // 初始化第0行，通过第0行构造第1行（真正待铺瓷砖的行为1~N)
    int width = pow(2, K);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < width; j++)
            if(dp[i%2][j])
                dfs(i, 0, j, 0);
        for(int j = 0; j < width; j++) dp[i%2][j] = 0; //初始化dp[i%2][]为0，实现滚动数组
    }
    cout << dp[N%2][0] << endl;
    return 0;
}