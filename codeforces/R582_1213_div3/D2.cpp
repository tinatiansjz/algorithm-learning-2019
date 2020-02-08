#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
const int maxn = 2e5+5;
const int INF = 0x3f3f3f3f;
int a[maxn];
vector<vector<int> > v(maxn);
int main(){
	// freopen("in.txt", "r", stdin);
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		int x = a[i], cnt = 0;
		v[x].push_back(0);
		do{
			x >>= 1;
			cnt++;
			v[x].push_back(cnt);
		}while(x > 0);
	}
	int ans = INF;
	for(int i = 0; i < maxn; i++){
		if(v[i].size() < k) continue;
		sort(v[i].begin(), v[i].end());
		ans = min(ans, accumulate(v[i].begin(), v[i].begin()+k, 0));
	}
	printf("%d\n", ans);
	return 0;
}