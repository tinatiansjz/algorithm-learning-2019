// HDU 6630
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const ll MOD = 998244353;
const int maxn = 1e5+5;
int N, x, y;
ll dp[maxn];
void cal(){
	// 从最左端蹦到最右端(按照题目要求)，一共有多少种方法。
	// 记长度为k，每一点都要经历且仅经过一次，且不经过此k个点之外的剩下的点
	dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for(int i = 4; i < maxn; i++)
		dp[i] = (dp[i-1]+dp[i-3])%MOD;
}
int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("fun.out", "w", stdout);
	int T; scanf("%d", &T);
	cal();
	while(T--){
		scanf("%d%d%d", &N, &x, &y);
		if(x > y) swap(x, y);
		int left = x-1, right = N-y, mid = y-x-1;
		if(left != 0 && mid == 0 && right != 0) {
			printf("0\n");
			continue;
		}
		if(mid == 0){
			printf("1\n");
			continue;
		}
		if(left == 0 && right == 0){
			printf("%d\n", (int)dp[N]);
			continue;
		}
		if(left == 0){ // eg. 6 5 1
			printf("%d\n", (int)dp[y-1]);
			continue;
		}
		if(right == 0){
			y = N+1-x;
			printf("%d\n", (int)dp[y-1]);
			continue;
		}
		printf("%d\n", (int)dp[mid]);
	}
	return 0;
}