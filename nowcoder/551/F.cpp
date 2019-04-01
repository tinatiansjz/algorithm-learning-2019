// https://ac.nowcoder.com/acm/contest/551/F
// 找规律，写到第五项
// v[i] = v[i-1]*(i*2-1)%MOD;
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const ll MOD = 998244353;
const int maxn = 1e6+5;
ll v[maxn];
void init(){
    v[0] = 1; v[1] = 1;
    for(int i = 2; i < maxn; i++){
        v[i] = v[i-1]*(i*2-1)%MOD;
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    init();
    int w, q; scanf("%d%d", &w, &q);
    while(q--){
        int tmp; scanf("%d", &tmp);
        printf("%lld\n", v[tmp]*w%MOD);
    }
    return 0;
}