// https://codeforces.com/blog/entry/66602
// https://codeforces.com/contest/1151/problem/C
// 前缀和
// 注意乘法每一步都要MOD，否则long long会溢出  即 a*b -> (a%MOD)*(b*MOD)%MOD
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
ll solve(ll n){
    ll odd = 0, even = 0;
    ll power = 0;
    while(n){
        ll tmp = min(n, (ll)pow(2, power));
        if(power&1){ // power is odd 
            even += tmp;
            n -= tmp;
        }else{
            odd += tmp;
            n -= tmp;
        }
        power++;
    }
    ll oddsum = (odd%MOD) * (odd%MOD) % MOD;
    ll evensum = (even%MOD) * ((even+1)%MOD) % MOD;
    return (oddsum+evensum) % MOD;
}
int main(){
    // freopen("in.txt", "r", stdin);
    ll l, r; cin >> l >> r;
    printf("%lld\n", (solve(r)-solve(l-1)+MOD)%MOD);
    return 0;
}