// sparse table
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e4+5;
int a[maxn];
int n, q;
int d1[maxn][20]; // min
int d2[maxn][20]; // max
void ST_init(){
    for(int i = 0; i < n; i++){
        d1[i][0] = d2[i][0] = a[i];
    }
    for(int i = 1; (1<<i) <= n; i++)
        for(int j = 0; j+(1<<i)-1 < n; j++){
            d1[j][i] = min(d1[j][i-1], d1[j+(1<<(i-1))][i-1]);
            d2[j][i] = max(d2[j][i-1], d2[j+(1<<(i-1))][i-1]);
        }
}
int ST_query(int L, int R){
    int k = 0;
    while((1<<(k+1)) <= R-L+1) k++; // 2^(k+1) <= R-L+1
    int _min = min(d1[L][k], d1[R-(1<<k)+1][k]);
    int _max = max(d2[L][k], d2[R-(1<<k)+1][k]);
    return _max-_min;
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    ST_init();
    for(int i = 0, L, R; i < q; i++){
        scanf("%d%d", &L, &R);
        L--; R--;
        cout << ST_query(L, R) << endl;
    }
    return 0;
}