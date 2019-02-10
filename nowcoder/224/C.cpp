//https://ac.nowcoder.com/acm/contest/224/C
//2018/11/8 15:05
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const ll MOD = 998244353;
const int maxn = 2000;
ll pp[maxn], rp[maxn];
ll C(ll m, ll n){
    if(m > n) return 0L;
    ll t = (pp[n]*rp[n-m])%MOD;
    t = (t*rp[m])%MOD;
    return t;
}
ll solve(ll n){
    ll ans = 0;
    for(ll k=1; k<=n; k++){
        for(ll j=1; j<=k; j++){
            for(ll i = 0; i < n; i++){
                ll t = C(k-j, i)*C(j-1, n-i-1);
                t %= MOD;
                t = (t*k)%MOD;
                ans = (ans+t)%MOD;
            }
        }
    }
    return ans;
}
void gcd(ll a, ll b, ll& d, ll& x, ll& y){
    if(!b){d = a; x = 1; y = 0;}
    else{
        gcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}
void init(){
    pp[0] = 1; rp[0] = 1;
    for(int i = 1; i < maxn; i++){
        pp[i] = (pp[i-1]*i) % MOD;
        ll y,x,d;
        gcd(pp[i], MOD, d, x, y);
        rp[i] = ((x%MOD)+MOD)%MOD;
    }
}
ll getn(ll n){
    ll t = n*(n+1) % MOD;
    n = n-2;
    ll ret = 1, a = 2;
    while(n){
        ret = n&1?(ret*a)%MOD:ret;
        a = a*a%MOD;
        n >>= 1;
    }
    return ret*t % MOD;
}
int main(){
    freopen("B_in.txt", "r", stdin);
    freopen("B_out.txt", "w", stdout);
    ll n;
    init();//burst initialize
    while(cin >> n){
        cout << getn(n) << " Burst: " << solve(n) << endl;
    }
    return 0;
}
