// HDU 1992
// dp
// https://blog.csdn.net/coraline_m/article/details/22219621
// 2019/2/12 11:33
// 将矩形区域调整为N*4
// 从上往下一行一行地铺，当前处理行只会受到上一行的影响。0表示不占用下一行的位置(0一定为偶数个），1表示第i个位置会占用下一行（即砖是竖着放的）
// dp[i][cur]表示处理完前i行，第i行状态为cur的方法数，cur为01序列的十进制表示。根据s用dfs构造出一个可行状态nex，那么dp[i+1][nex] += dp[i][cur]
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1000+5;
int dp[maxn][16];
void dfs(int r, int c, int cur, int nex){// N*4
    //当前行 当前列 当前状态 可转移状态
    //已知r行状态cur，构造r+1行状态nex
    if(c > 3){
        dp[r+1][nex] += dp[r][cur];
        return;
    }
    if(!(cur & (1<<c))){// cur[c] == 0
        dfs(r, c+1, cur, nex | (1<<c));// nex[c] = 1,即竖着放
        if(c <= 2 && !(cur&(1<<(c+1))))// cur[c] == 0 && cur[c+1] == 0
            dfs(r, c+2, cur, nex);// nex[c],nex[c+1]可以横铺一个
    }else{
        dfs(r, c+1, cur, nex);// nex[c]已被上一行占用，直接跳过
    }
}
int main(){
    freopen("in.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < 22; i++)// 22已经爆int32了
        for(int j = 0; j < 16; j++)
            if(dp[i][j])
                dfs(i, 0, j, 0);
    int T; cin >> T;
    for(int i = 1, x; i <= T; i++){
        cin >> x;
        cout << i << " " << dp[x][0] << endl;
    }
    return 0;
}
