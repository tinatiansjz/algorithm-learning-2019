#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll a, b, c, d;
ll x, y;
ll gcd(ll p, ll q){
	return q == 0 ? p : gcd(q, p%q);
}
int main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	ll n, m, q; cin >> n >> m >> q;
	while(q--){
		cin >> a >> b >> c >> d;
		ll tmp = gcd(n, m);
		x = n/tmp; y = m/tmp;
		b--; d--;
		if(a == 1 && c == 1){
			if(b/x == d/x) cout << "YES" << endl;
			else cout << "NO" << endl;
		}else if(a == 1 && c == 2){
			if(b/x == d/y) cout << "YES" << endl;
			else cout << "NO" << endl;
		}else if(a == 2 && c == 1){
			if(b/y == d/x) cout << "YES" << endl;
			else cout << "NO" << endl;
		}else if(a == 2 && c == 2){
			if(b/y == d/y) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}