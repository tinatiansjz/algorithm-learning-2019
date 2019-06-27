#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const ll maxk = 1e12+5;
const ll maxn = 100+5;
char a[maxn];
// dp[i][j]: 考虑到a[j]，长度为i的sub-sequence的个数
ll dp[maxn][maxn];
bool kmap[300];
void init(){
    memset(kmap,0,sizeof(kmap));
}
int main(){
    // freopen("in.txt", "r", stdin);
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    cin>>(a+1);
    init();
    ll cnt = 0;
    for(ll i = n; i >= 1; i--) {
        dp[0][i] = 1LL;
        if(kmap[a[i]]==false){kmap[a[i]]=true;cnt++;}
        dp[1][i] = cnt;
    }
    for(ll i = 2; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            init();
            ll tmp = 0;
            for(ll z=j;z<=n;z++){
                if(kmap[a[z]]==0 && z+1 <= n){
                    tmp += dp[i-1][z+1];
                    kmap[a[z]] = true;
                }
            }
            dp[i][j] = min((ll)1e14, tmp);
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    ll ans = 0;
    for(ll i = n; i >= 0 && k>0; i--){
        ll v = min(1LL*k,dp[i][1]);
        ans += v*(n-i);
        k -= v;
    }
    if(k > 0) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}