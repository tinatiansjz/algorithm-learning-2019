//CodeForces - 869B
//2018/10/29    11:21
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main(){
#ifdef LOCAL
    freopen("cf869b_in.txt", "r", stdin);
#endif
    ll a, b;
    while(cin >> a >> b){
        if(b - a >= 10){
            cout << "0" << endl;
            continue;
        }else{
            ll ans = 1;
            for(ll i = a+1; i <= b; i++){
                ans = ans*i % 10;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
