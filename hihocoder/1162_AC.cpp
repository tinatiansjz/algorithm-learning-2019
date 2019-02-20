// http://hihocoder.com/problemset/problem/1162
// dfs, dp, fast power
// 2019/02/17 17:14
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
const int maxk = 128;
const int MOD = 12357;
// int dp[maxk][maxk];
int K, N, width;
struct mat{
    ll a[maxk][maxk];
    int l, r;
}A, B, C;
mat operator * (mat X, mat Y){
    mat Z; Z.l = X.l; Z.r = Y.r;
    for(int i = 0; i < X.l; i++)
        for(int j = 0; j < Y.r; j++){
            Z.a[i][j] = 0;
            for(int k = 0; k < X.r; k++)
                Z.a[i][j] = (Z.a[i][j] + X.a[i][k]*Y.a[k][j]%MOD)%MOD;
        }
    return Z;
}
void init(){
    width = pow(2, K);
    A.l = 1; A.r = width; A.a[0][width-1] = 1;
    C.l = C.r = B.l = B.r = width;
    for(int i = 0; i < width; i++) C.a[i][i] = 1; // identity matrix
}
void dfs(int x, int y, int col){
    if(col >= K) {B.a[y][x] = 1; return;}
    // 每一种放置方法解释如下，假设当第i行的状态为x，第i-1行的状态为y:
    // 1. 第i行不放置，则前一行必须有放置的骨牌。x对应二进制位为0，y对应二进制位为1
    dfs(x<<1, (y<<1)+1, col+1);
    // 2. 第i行竖放骨牌，则前一行必须为空。x对应二进制位为1，y对应二进制位为0
    dfs((x<<1)+1, y<<1, col+1);
    // 第i行横向骨牌，则前一行必须两个位置均有骨牌，否则会产生空位。x对应二进制位为1，y对应二进制位为1
    if(col+2 <= K)
        dfs((x<<2)+3, (y<<2)+3, col+2);
}
void debug(){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++) cout << B.a[i][j] << " ";
        cout << endl;
    }
}
void cal(){
    while(N){
        if(N&1) C = C*B;
        B = B*B;
        N >>= 1;
    }
    A = A*C;
    cout << A.a[0][width-1] << endl;
}
int main(){
    freopen("in.txt", "r", stdin);
    cin >> K >> N;
    init();
    dfs(0, 0, 0);// calculate the transform matrix (dp)
    // debug();
    cal();// matrix fast power
    return 0;
}
