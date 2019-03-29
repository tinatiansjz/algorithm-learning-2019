// 树状数组 莫队算法
// 2019/03/24
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define ll long long
const int maxn = 2e4+5;
int a[maxn], tot = 0;
long long Ans[maxn], ans = 0;
struct node{
    int l, r, id, bl;
}q[maxn];
inline int lowbit(int x) {return x&(-x);}
struct FenwickTree{
    int C[maxn];
    void clear(){memset(C, 0, sizeof(C));}
    int sum(int x){
        int ret = 0;
        while(x > 0){
            ret += C[x];
            x -= lowbit(x);
        }
        return ret;
    }
    void add(int x, int d){
        while(x < maxn){
            C[x] += d; x += lowbit(x);
        }
    }
};
FenwickTree t, cnt;
bool cmp(node a, node b){
    return (a.bl ^ b.bl) ? (a.l < b.l) : (a.bl&1) ? (a.r > b.r) : (a.r < b.r);
}
void add(int x){
    ans += t.sum(a[x]);
    int num = tot - cnt.sum(a[x]);
    ans += (ll)(num+1L)*(ll)a[x];
    t.add(a[x], a[x]);
    cnt.add(a[x], 1);
    tot++;
}
void del(int x){
    int num = tot - cnt.sum(a[x]);
    ans -= (num+1)*a[x];
    t.add(a[x], -a[x]);
    cnt.add(a[x], -1);
    ans -= t.sum(a[x]);
    tot--;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--){
        memset(q, 0, sizeof(q));
        cnt.clear(); t.clear();
        ans = 0; tot = 0;
        int n, m; scanf("%d%d", &n, &m);
        int block = sqrt(n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i; q[i].bl = q[i].l / block;
        }
        sort(q+1, q+m+1, cmp);
        int r = 1, l = 1; ans = a[1]; tot = 1;
        cnt.add(a[1], 1); t.add(a[1], a[1]);
        for(int i = 1; i <= m; i++){
            int ql = q[i].l, qr = q[i].r;
            while(r < qr) add(++r);
            while(l > ql) add(--l);
            while(r > qr) del(r--);
            while(l < ql) del(l++);
            Ans[q[i].id] = ans;
        }
        for(int i = 1; i <= m; i++){
            printf("%lld\n", Ans[i]);
        }
    }
    return 0;
}
