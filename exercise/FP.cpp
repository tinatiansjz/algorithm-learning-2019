#include <iostream>
#include <cstdio>
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
ll fastpower(ll a, ll n){
    ll ans = 1L;
    a %= mod;
    while(n){
        ans = n&1 ? (ans*a)%mod : ans;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    cout << fastpower(3, 6) << endl;
    return 0;
}
