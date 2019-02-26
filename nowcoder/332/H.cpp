// https://ac.nowcoder.com/acm/contest/332/H
// 2019/2/8 21:54
// 枚举 贪心
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 2005;
ll a[2005], b[2005], x, ans = 0;
int main(){
    int n; scanf("%d%lld", &n, &x);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        ans += a[i];
        b[i] = a[i];
    }
    for(int k = 1; k < n; k++){
        ll xx = x*k;
        for(int i = 0; i < n; i++){
            b[i] = min(b[i], a[(i-k+n)%n]);
            xx += b[i];
        }
        ans = min(ans, xx);
    }
    cout << ans << endl;
    return 0;
}