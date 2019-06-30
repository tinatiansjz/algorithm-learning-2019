// UVa 1400
#include <iostream>
#include <cstdio>
#define lc (o<<1)
#define rc ((o<<1)+1)
#define ll long long
#define mp make_pair
#define pii pair<int, int>
using namespace std;
const int maxn = 5e5+5;
const int maxo = maxn<<2;
int a[maxn];
int n, m;
int qL, qR;
ll prefix_sum[maxn];// 前缀和
// 记录的为下标
// max_sub: [max_sub[o].first, max_sub[o].second]
pair<int, int> max_sub[maxo]; // 最大连续和
int max_prefix[maxo]; // 最大前缀和
int max_suffix[maxo]; // 最大后缀和
ll sum(int L, int R){
    return prefix_sum[R]-prefix_sum[L-1];
}
ll sum(pii a){
    return sum(a.first, a.second);
}
pii better(pii a, pii b){
    if(sum(a) != sum(b)) return sum(a) > sum(b) ? a : b;
    return a < b ? a : b; // 利用pair自带的字典序
}
void build(int o, int L, int R){
    if(L == R) {
        max_suffix[o] = max_prefix[o] = L;
        max_sub[o] = mp(L, L);
        return;
    }
    int M = (L+R)/2;
    build(lc, L, M);
    build(rc, M+1, R);
    // 递推max_prefix
    ll v1 = sum(L, max_prefix[lc]);
    ll v2 = sum(L, max_prefix[rc]);
    if(v1 == v2) max_prefix[o] = max_prefix[lc];
    else max_prefix[o] = v1 > v2 ? max_prefix[lc] : max_prefix[rc];
    // 递推max_suffix
    v1 = sum(max_suffix[lc], R);
    v2 = sum(max_suffix[rc], R);
    if(v1 == v2) max_suffix[o] = max_suffix[lc];
    else max_suffix[o] = v1 > v2 ? max_suffix[lc] : max_suffix[rc];
    // 递推max_sub
    max_sub[o] = better(max_sub[lc], max_sub[rc]);
    max_sub[o] = better(max_sub[o], mp(max_suffix[lc], max_prefix[rc]));
}
pii query_prefix(int o, int L, int R){
    if(max_prefix[o] <= qR) return mp(L, max_prefix[o]);
    int M = (L+R)/2;
    if(qR <= M) return query_prefix(lc, L, M);
    pii i = query_prefix(rc, M+1, R);
    i.first = L;
    return better(i, mp(L, max_prefix[lc]));
}
pii query_suffix(int o, int L, int R){
    if(qL <= max_suffix[o]) return mp(max_suffix[o], R);
    int M = (L+R)/2;
    if(qL > M) return query_suffix(rc, M+1, R);
    pii i = query_suffix(lc, L, M);
    i.second = R;
    return better(i, mp(max_suffix[rc], R)); 
}
pii query(int o, int L, int R){
    if(qL <= L && qR >= R) return max_sub[o];
    int M = (L+R)/2;
    if(qR <= M) return query(lc, L, M);
    if(qL > M) return query(rc, M+1, R);
    pii i1 = query_suffix(lc, L, M);
    pii i2 = query_prefix(rc, M+1, R);
    pii i3 = better(query(lc, L, M), query(rc, M+1, R));
    return better(i3, mp(i1.first, i2.second));
}
int main(){
    // freopen("in.txt", "r", stdin);
    int kase = 0;
    while(scanf("%d%d", &n, &m) == 2){
        prefix_sum[0] = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i+1]);
            prefix_sum[i+1] = prefix_sum[i]+a[i+1];
        }
        build(1, 1, n);
        printf("Case %d:\n", ++kase);
        while(m--){
            scanf("%d%d", &qL, &qR);
            pii ans = query(1, 1, n);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}