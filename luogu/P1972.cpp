// 莫队算法
// 2019/03/23 18:57
// https://blog.csdn.net/weixin_43907802/article/details/86773471
// Tips: inline
//       奇偶性优化
// score: 90    -O2  TLE
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e5+5;
const int maxi = 1e6+5;
int a[maxn], cnt[maxi], Ans[maxn];
int ans = 0;
struct node{
    int l, r, id, bl;
}e[maxn];
// 对于左端点在同一奇数块的区间，右端点按升序排列，反之降序
inline bool cmp(node a, node b){
    return (a.bl)^(b.bl) ? a.l<b.l : (a.bl&1)?a.r<b.r:a.r>b.r;
}
inline void add(int x){
    if(!cnt[a[x]]) ans++;
    cnt[a[x]]++;
}
inline void del(int x){
    cnt[a[x]]--;
    if(!cnt[a[x]]) ans--;
}
int main(){
    // freopen("in.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
    int M; scanf("%d", &M);
    int block = N/sqrt(M*2/3);
    for(int i = 0; i < M; i++){
        e[i].id = i;
        scanf("%d%d", &e[i].l, &e[i].r);
        e[i].bl = e[i].l / block;
    }
    sort(e, e+M, cmp);
    int l = 0, r = 0;
    for(int i = 0; i < M; i++){
        int ql = e[i].l, qr = e[i].r;
        while(l < ql) del(l++);
        while(l > ql) add(--l);
        while(r < qr) add(++r);
        while(r > qr) del(r--);
        Ans[e[i].id] = ans;
    }
    for(int i = 0; i < M; i++) printf("%d\n", Ans[i]);
}
