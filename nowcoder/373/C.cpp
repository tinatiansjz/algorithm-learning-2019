// Uion-find set
// Attention: long long
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e5+5;
int fa[maxn], a[maxn], N, M;
ll cnt[maxn];
bool vis[maxn];
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void init(){
    for(int i = 1; i <= N; i++) fa[i] = i;
    memset(vis, 0, sizeof(vis));
}
bool cmp(const ll & A, const ll & B){
    return A > B;             //如果修改为return A<B就还原为了升序排列
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    init();
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= N; i++){
        int tmp; scanf("%d", &tmp);
        int fatmp = find(tmp), fai = find(i);
        if(fatmp != fai) fa[fai] = fatmp;
    }
    for(int i = 1; i <= N; i++){
        int f = find(i);
        cnt[f] += 1LL*a[i];
    }
    sort(cnt+1, cnt+N+1, cmp);
    ll ans = 0;
    for(int i = 1; i <= M; i++) ans += cnt[i];
    cout << ans << endl;
    return 0;
}