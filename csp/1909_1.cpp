#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1000+5;
int a[maxn];
int ans[maxn];
int del[maxn];
int main(){
//	cin.tie(0); ios_base::sync_with_stdio(false);
//	freopen("in.txt", "r", stdin);
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1, init; i <= n; i++){
		scanf("%d", &init);
		int cur = init;
		for(int j = 1, now; j <= m; j++){
			scanf("%d", &now);
			cur = cur+now;
		}
		a[i] = cur;
		del[i] = init-cur;
	}
	ll Sum = 0;
	for(int i = 1; i <= n; i++) Sum += 1LL*a[i];
	int _max = 0, id = 0;
	for(int i = 1; i <= n; i++){
		if(del[i] > _max){
			_max = del[i];
			id = i;
		}
	}
	cout << Sum << " " << id << " " << _max << endl;
	return 0;
}
