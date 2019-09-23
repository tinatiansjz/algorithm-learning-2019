#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 2e5+5;
int n, m;
int fa[maxn];
int rk[maxn]; // the size of each part
ll ans[maxn];
ll res = 0;
inline ll get(int s){return 1LL*s*(s-1)/2;}
int find(int x){
	return x == fa[x] ? x : fa[x]=find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx != fy){
		res -= get(rk[fx]);
		res -= get(rk[fy]);
		fa[fx] = fy;
		rk[fy] += rk[fx];
		res += get(rk[fy]);
	}
}
void init(){
	for(int i = 0; i < n; i++){
		fa[i] = i;
		rk[i] = 1;
	}
}
int main(){
	// freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init();
	vector<pair<int, pair<int, int> > > e(n-1);
	vector<pair<int, int> > q(m); // query
	for(int i = 0; i < n-1; i++){
		scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first);
		e[i].second.first--;
		e[i].second.second--;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &q[i].first);
		q[i].second = i;
	}
	sort(e.begin(), e.end());
	sort(q.begin(), q.end());
	int pos = 0;
	for(int i = 0; i < m; i++){
		int cur = q[i].first;
		while(pos < n-1 && e[pos].first <= cur){
			merge(e[pos].second.first, e[pos].second.second);
			pos++;
		}
		ans[q[i].second] = res;
	}
	for(int i = 0; i < m; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}