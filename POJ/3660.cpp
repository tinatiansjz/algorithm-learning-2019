// Floyd
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100+5;
const int maxm = 45000+5;
const int INF = 0x3f3f3f3f;
int e[maxn][maxn];
int n, m;
void init(){
	memset(e, INF, sizeof(e));
	for(int i = 0; i <= n; i++) e[i][i] = 0;
}
void floyd(){
	for(int k = 1; k <= n; k++){ // 经过第k号节点
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(e[i][j] > e[i][k]+e[k][j])
					e[i][j] = e[i][k]+e[k][j];
			}
		}
	}
}
int main(){
	// freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init();
	for(int i = 0, from, to; i < m; i++){
		scanf("%d%d", &from, &to);
		e[from][to] = 1;
	}
	floyd();
	int ans = 0;
	for(int i = 1, cnt; i <= n; i++){
		cnt = 0;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(e[i][j] < n || e[j][i] < n) cnt++;
		}
		if(cnt == n-1) ans++;
	}
	cout << ans << endl;
	return 0;
}