#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000+5;
// (x, y): x refers to the number and y the value
// (y+2520)%m = y%m
const int maxs = 2520+5; // maximum amount of states of one vertex
const int mod = 2520;
int K[maxn], M[maxn];
int G[maxn][15];
int S[maxn][maxs];
bool vis[maxn][maxs], b[maxn];
int dfs(int x, int y){ // the vertex and the value
	y = (K[x]+y)%mod;
	if(S[x][y] != -1) return S[x][y];
	if(!vis[x][y]){
		vis[x][y] = true;
		int _next = G[x][y%M[x]];
		S[x][y] = dfs(_next, y);
		vis[x][y] = false;
		return S[x][y];
	}
	// vis[x][y] == true
	int ref = 0, u = x, v = y;
	do{
		u = G[u][v%M[u]];
		v = (v+K[u])%mod;
		if(!b[u]) {ref++; b[u] = true;}
	}while(u != x || v != y);
	u = x, v = y;
	do{
		u = G[u][v%M[u]];
		v = (v+K[u])%mod;
		b[u] = false;
	}while(u != x || v != y);
	return S[x][y] = ref;
}
int main(){
	// freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &K[i]);
		K[i] = (K[i]%mod+mod)%mod;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &M[i]);
		for(int j = 0; j < M[i]; j++){
			scanf("%d", &G[i][j]);
		}
	}
	int q; scanf("%d", &q);
	memset(S, -1, sizeof(S));
	while(q--){
		int x, y; scanf("%d%d", &x, &y);
		y = (y%mod+mod)%mod;
		int ans = dfs(x, y);
		printf("%d\n", ans);
	}
	return 0;
}