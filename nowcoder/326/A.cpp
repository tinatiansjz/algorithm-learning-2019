#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    int T; cin >> T;
    while(T--){
        ll N;
        scanf("%lld", &N);
        if(N%2 == 1){cout << "NO\n"; continue;}
        int ans = 0;
        ll j = N;
        for(int i = 0; i < 64; i++){
            ans += 1 & j;
            j >>= 1;
        }
        // cout << "ans = " << ans << endl;
        if(ans <= 2 && N > 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}