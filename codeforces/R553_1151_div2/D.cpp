// n*v[i].b 会溢出int, 记住转化为long long
// https://codeforces.com/contest/1151/problem/D
#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5+5;
struct node{
    int id, a, b, diff;
}v[maxn];
bool cmp(node x, node y){
    return (x.diff == y.diff) ? (x.id < y.id) : (x.diff > y.diff);
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &v[i].a, &v[i].b);
        v[i].id = i;
        v[i].diff = v[i].a - v[i].b;
    }
    sort(v+1, v+n+1, cmp);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += 1LL*(v[i].a-v[i].b)*i + 1LL*(1LL*n*v[i].b-1LL*v[i].a);
    }
    cout << ans << endl;
    return 0;
}