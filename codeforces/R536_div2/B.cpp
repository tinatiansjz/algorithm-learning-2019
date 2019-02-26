// 2019/2/1 08:35
// https://codeforces.com/contest/1106/problem/B
// 模拟题
// 注意ans是long long范围! 否则会WA
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int n, m;
set<pair<int, int> > s;
const int maxn = 1e5+10;
int a[maxn], r[maxn];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
        s.insert(pair<int,int>{r[i],i});//cost, id
    }
    for(int i = 0; i < m; i++){
        int t, d;
        scanf("%d%d", &t, &d);
        if(a[t]>=d){
            a[t] -= d; printf("%I64d\n", 1LL*d*r[t]);
            if(a[t] == 0) s.erase(pair<int, int>{r[t], t});
            continue;
        }
        long long ans = 0;
        s.erase(pair<int, int>{r[t], t});
        ans += 1LL*a[t]*r[t];
        d -= a[t]; a[t] = 0;
        while(d && !s.empty()){
            set<pair<int, int> >::iterator it = s.begin();
            if(a[it->second] >= d){
                a[it->second] -= d;
                ans += 1LL*d*r[it->second];
                if(a[it->second] == 0) s.erase(it);
                d = 0;
            }else{
                ans += 1LL*r[it->second]*a[it->second];
                d -= a[it->second]; a[it->second] = 0;
                s.erase(it);
            }
        }
        if(d) puts("0");
        else printf("%I64d\n", ans);
    }
    return 0;
}
