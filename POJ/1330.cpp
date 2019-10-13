// LCA
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000+5;
const int maxh = 15; // 2**maxh > maxn
// graph
int n;
int head[maxn];
int tot = 0;
struct edges{
	int v, next;
}E[maxn<<1];

int in[maxn];
int d[maxn];
int fa[maxn][maxh];

void init(){
	// memset(d, 0, sizeof(d));
	// memset(fa, 0, sizeof(fa));
	memset(in, 0, sizeof(in));
	memset(head, -1, sizeof(head));
	tot = 0;
}
void add_edge(int u, int v){
	E[tot].v = v; E[tot].next = head[u];
	head[u] = tot;
	tot++;
}

void dfs(int x, int f){
	d[x] = d[f]+1;
	fa[x][0] = f;
	for(int i = 1; (1<<i) <= n; i++)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i = head[x]; ~i; i = E[i].next){
		int y = E[i].v;
		if(y == f) continue;
		dfs(y, x);
	}
}
int LCA(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	int w = 0;
	while((1<<w) <= n) w++;
	for(int i = w; i >= 0; i--){
		if(d[x]-(1<<i) >= d[y]) x = fa[x][i];
	}
	// now, d[x] == d[y]
	if(x == y) return x;
	for(int i = w; i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	// freopen("in.txt", "r", stdin);
	int T; scanf("%d", &T);
	while(T--){
		init();
		scanf("%d", &n);
		for(int i = 0, from, to; i < n-1; i++){
			scanf("%d%d", &from, &to);
			in[to]++;
			add_edge(from, to);
			add_edge(to, from);
		}
		d[0] = -1;
		int root = 0;
		for(int i = 1; i <= n; i++)
			if(in[i] == 0) {root = i; break;}
		dfs(root, 0);
		int u, v;
		scanf("%d%d", &u, &v);
		// cout << u << " " << v << endl;
		printf("%d\n", LCA(u, v));
	}
	return 0;
}