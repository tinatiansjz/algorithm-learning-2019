// dp
// dp[i][j][k] 现在排了i个男生，j个女生，并且以k个男生作为结尾
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int maxn = 100+5;
const int maxk = 100+5;
//const int maxn = 5;
//const int maxk = 5;
const int MOD = 10007; 
ll dp[maxn][maxn][maxk];
int main(){
//	freopen("in.txt", "r", stdin);
	int B, G, K; cin >> B >> G >> K;
	dp[1][0][1] = 1; dp[0][1][0] = 1;
	for(int i = 0; i <= B; i++){
		for(int j = 0; j <= G; j++){
			for(int k = 0; k <= K; k++){
				if(i > 0 && k > 0)
					dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k-1])%MOD;
				if(j > 0)
					dp[i][j][0] = (dp[i][j][0]+dp[i][j-1][k])%MOD;
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= K; i++){
		ans = (ans+dp[B][G][i])%MOD;
	}
	cout << ans << endl; 
	return 0;
}