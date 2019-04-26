// 质数筛 hihocoder 1493
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
// #include <map>
using namespace std;
const int maxn = 1e6+5;
bool isPrime[maxn];
vector<int> v;
int main(){
	// freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	memset(isPrime, 1, sizeof(isPrime));
	int cnt = 0;
	for(int i = 2; i <= n; i++){
		if(isPrime[i]){
			v.push_back(i);
			cnt++;
		}
		for(int j = 0; j < cnt; j++){
			if(1LL*i*v[j] > n) break;
			isPrime[i*v[j]] = false;
			if(i%v[j] == 0) break;
		}
	}
	int i;
	for(i = 2; i <= n/2; i++){
		if(isPrime[i] && isPrime[n-i]){
			printf("%d %d\n", i, n-i);
			break;
		}
	}
	return 0;
}