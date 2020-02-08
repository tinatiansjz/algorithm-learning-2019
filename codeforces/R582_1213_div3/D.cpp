#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 100;
const int maxp = 1000;
const int INF = 0x3f3f3f3f;
int a[maxn];
vector<int> v;
vector<int> cnt;
int main(){
	// cin.tie(0); ios_base::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		int x = a[i];
		do{
			v.push_back(x);
			x >>= 1;
		}while(x > 0);
	}
	v.push_back(0);
	sort(v.begin(), v.end(), greater<int>());
	int len = unique(v.begin(), v.end())-v.begin();
	int ans = INF;
	for(int i = 0; i < len; i++){
		int thre = v[i];
		int cnt = 0, t = 0;
		for(int j = 1; j <= n && cnt < k; j++){
			if(a[j] < thre) continue;
			if(a[j] == thre) {cnt++; continue;}
			int x = a[j], tmp = 0;
			do{
				x >>= 1;
				tmp++;
			}while(x > thre);
			if(x == thre) {cnt++; t += tmp;}
		}
		if(cnt >= k) ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}