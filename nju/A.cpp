// 贪心 O(n^2)
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100+5;
char a[maxn];
bool vis[maxn];
int n, k;
int main(){
	freopen("data.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int T; cin >> T;
	while(T--){
		scanf("%s", a);
		scanf("%d", &k);
		int len = strlen(a);
		if(len == k){
			printf("0\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		while(k--){
			int j = 0, cur, next;
			while(j < len){
				while(vis[j]) j++;
				cur = j;
				j++;
				while(vis[j]) j++;
				next = j;
				if(a[cur] > a[next]){
					vis[cur] = true;
					break;
				}
			}
		}
		for(int i = 0; i < len; i++)
			if(!vis[i]) printf("%c", a[i]);
		printf("\n");
	}
	return 0;
}