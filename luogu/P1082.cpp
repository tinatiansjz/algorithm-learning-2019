// https://www.luogu.org/problemnew/show/P1082
// 同余方程     扩展欧几里得
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }else{
        ll r = exgcd(b, a%b, y, x);
        y -= x*(a/b);
        return r;
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    ll a, b; cin >> a >> b;
    ll x, y;
    exgcd(a, b, x, y);
    while(x < 0) x = x+b;
    if(x > 0) x = x%b;
    cout << x << endl;
    return 0;
}
