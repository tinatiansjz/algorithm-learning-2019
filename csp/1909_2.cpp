#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1000+5;
int cnt[maxn];
int init[maxn];
int final[maxn];
bool del[maxn];
int main(){
//	cin.tie(0); ios_base::sync_with_stdio(false);
//	freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	for(int i = 1, m; i <= n; i++){
		scanf("%d", &m);
		scanf("%d", &init[i]);
		int cur = init[i];
		for(int j = 1, op; j < m; j++){
			scanf("%d", &op);
			if(op > 0){
				if(cur > op) del[i] = true;
				cur = op;
			}else{
				cur = cur+op;
			}
		}
		final[i] = cur;
	}
	ll Sum = 0;
	for(int i = 1; i <= n; i++) Sum += 1LL*final[i];
	int delnum = 0;
	for(int i = 1; i <= n; i++){
		if(del[i]){
			delnum++;	
		}
	}
	int group = 0;
	for(int i = 1; i <= n; i++){
		if(del[i]&del[i%n+1]&del[(i+1)%n+1]) group++;
	}
	cout << Sum << " " << delnum << " " << group << endl;
	return 0;
}
