// https://codeforces.com/contest/1151/problem/F
// https://codeforces.com/blog/entry/66602
// dp[i][j] = dp[i-1][j-1] * (cnt-j)*(cnt-j)    [f10 = (cnt-j)*(cnt-j)]
//          + dp[i-1][j+1] * j*(n+j-2*cnt)      [f01 = j*(n+j-2*cnt)]
//          + dp[i-1][j] * n*(n-1)/2 - f10 - f01
// 2019/04/23   11:17
// 一定要注意MOD！！！每一处都不能落下
// 转移矩阵 + 矩阵快速幂
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 100+5;
const int MOD = 1e9+7;
int a[maxn];
ll dp[maxn];
struct mat{
    ll a[maxn][maxn];
    int l, r;
    void init(int _l, int _r){
        memset(a, 0, sizeof(a));
        l = _l; r = _r;
    }
};
mat operator * (mat X, mat Y){
    mat Z;
    Z.l = X.l; Z.r = Y.r;
    for(int i = 0; i < X.l; i++)
        for(int j = 0; j < Y.r; j++){
            Z.a[i][j] = 0;
            for(int k = 0; k < X.r; k++)
                Z.a[i][j] = (Z.a[i][j]+X.a[i][k]*Y.a[k][j]%MOD)%MOD;
        }
    return Z;
}
int n, k, cnt = 0, pre = 0;
mat trans, iden;

inline ll f10(int j){return (cnt-j)*(cnt-j);}
inline ll f01(int j){return (n+j-2*cnt)*j;}
inline ll f_eq(int j){return n*(n-1)/2-f10(j)-f01(j);}

void debug(mat trans){
    for(int i = 0; i <= cnt; i++){
        for(int j = 0; j <= cnt; j++)
            cout << trans.a[i][j] << " ";
        cout << endl;
    }
}
void init(){
    trans.init(cnt+1, cnt+1); iden.init(cnt+1, cnt+1);
    for(int j = 0; j <= cnt; j++){
        iden.a[j][j] = 1;
        if(n+j-2*cnt < 0) continue;
        trans.a[j][j] = f_eq(j);
        if(j > 0) trans.a[j][j-1] = f01(j);
        if(j < cnt) trans.a[j][j+1] = f10(j); 
    }
    // debug(trans);
}
void mult(){ // mult(mat trans, k)
    while(k){
        if(k&1) iden = iden*trans;
        trans = trans*trans;
        k >>= 1;
    }
}
ll _pow(ll a, int k){
    ll base = a, ans = 1;
    while(k){
        if(k&1) ans = ans*base%MOD;
        base = base*base%MOD;
        k >>= 1;
    }
    return ans;
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(!a[i]) cnt++;
    }
    for(int i = 0; i < cnt; i++)
        if(!a[i]) pre++;
    init();
    mult();
    // debug(iden);
    ll P = 0, Q = 0;
    for(int i = 0; i <= cnt; i++)
        Q = (Q+iden.a[pre][i]%MOD)%MOD;
    P = iden.a[pre][cnt]%MOD;
    ll Q_1 = _pow(Q, MOD-2);
    cout << P*Q_1%MOD << endl;
    return 0;
}