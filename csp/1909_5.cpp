// 过了样例，没有找到可以学习的博客
// lca + 暴力枚举每种选择
// 评测0分，哭唧唧
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 5e4+5;
const int maxm = 1e4+5;
const int maxk = 100+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
// graph
int n, m, k;
struct edge{
	int v, w, next;
}E[maxn<<1];
int head[maxn];
int tot;
// candidate key cities
int can[maxm];
int sel[maxk];
void add_edge(int u, int v, int w){
	E[tot].v = v; E[tot].w = w;
	E[tot].next = head[u];
	head[u] = tot;
	tot++;
}
void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}
ll res = INF;
// LCA
int fa[maxn][18];
int d[maxn];
int path[maxn]; // the path length to root
void dfs(int x, int f, int len){
	d[x] = d[f]+1;
	path[x] = path[f]+len;
	fa[x][0] = f;
	for(int i = 1; (1<<i) <= n; i++)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i = head[x]; ~i; i = E[i].next){
		int v = E[i].v;
		if(v == f) continue;
		int w = E[i].w;
		dfs(v, x, w);
	}
}
int lca(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	int w = 0;
	while((1<<w) <= n) w++;
	for(int i = w; i >= 0; i--)
		if(d[x]-(1<<i) > d[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i = w; i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int getDis(int x, int y){
	int z = lca(x, y);
	return path[x]+path[y]-2*path[z];
}
ll cal(){
	ll ans = 0;
	for(int i = 0; i < k-1; i++)
		for(int j = i+1; j < k; j++)
			ans += 1LL*getDis(sel[i], sel[j]);
	return ans;
}
void choose(int cur, int num){
	if(num == k){
		res = min(res, cal());
		// for(int i = 0; i < k; i++) cout << sel[i] << " ";
		// cout << cal() << endl;
		return;
	}
	for(int i = cur; i < m; i++){
		sel[num] = can[i];
		choose(i+1, num+1);
	}
}
int main(){
	// freopen("in.txt", "r", stdin);
	init();
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++) scanf("%d", &can[i]);
	for(int i = 0, u, v, w; i < n-1; i++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	d[0] = -1;
	dfs(1, 0, 0);
	choose(0, 0);
	cout << res << endl;
	return 0;
}