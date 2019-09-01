// 随机算法
// 哈希值
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e6+5;
const int maxs = 1e6+5;
const int MOD1 = 1000000007, MOD2 = 998244353;
char s[maxn];
char ans[maxs];
int len = 0, ss, cnt;
int r1, r2;
int b1[maxn], b2[maxn];
ll c1, d1, c2, d2;
void pre(){
	r1 = rand() % MOD1;
	r2 = rand() % MOD2;
	b1[0] = 1, b2[0] = 1;
	for(int i = 1; i < maxn; i++){
		b1[i] = 1LL*b1[i-1]*r1 % MOD1;
		b2[i] = 1LL*b2[i-1]*r2 % MOD2;
	}
}
void init(){
	cnt = 0; // the length of partition which overlaps with the ans
	c1 = 0, c2 = 0, d1 = 0, d2 = 0;
}
int main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	freopen("in.txt", "r", stdin);
	srand(time(NULL));
	int n; cin >> n;
	pre();
	while(n--){
		cin >> s;
		ss = strlen(s);
		init();
		for(int i = 1; i <= min(len, ss); i++){
			c1 = (c1 + 1LL*ans[len-i]*b1[i-1] % MOD1) % MOD1; // ans
			c2 = (c2 + 1LL*ans[len-i]*b2[i-1] % MOD2) % MOD2;
			d1 = (d1*r1 + s[i-1]) % MOD1;
			d2 = (d2*r2 + s[i-1]) % MOD2;
			if(c1 == d1 && c2 == d2) cnt = i;
		}
		for(int i = cnt; i < ss; i++)
			ans[len++] = s[i];
	}
	cout << ans << endl;
	return 0;
}