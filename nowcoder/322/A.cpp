// Fast power
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod = 1e7 + 19;
ll fastpower(ll a, ll n){
    ll ans = 1L;
    a = a%mod;
    while(n){
        ans = (n&1) ? (ans*a)%mod : ans;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n; cin >> n;
    ll ans = 0L;
    for(int i = 1; i <= n; i++){
        ll tmp;
        scanf("%lld", &tmp);
        ans = (ans + fastpower(tmp, i))%mod;
    }
    cout << ans << endl;
    return 0;
}