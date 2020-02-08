#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int n, m, k;
const int maxn = 110;
int a[maxn];
int main(){
	// freopen("in.txt", "r", stdin);
	int T; cin >> T;
	while(T--){
		bool flag = true;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < n-1; i++){
			if(abs(a[i+1]-a[i]) <= k || a[i] > a[i+1]){
				m += a[i] - max(a[i+1]-k, 0);
			}else{ // a[i] < a[i+1]-k
				if(m < a[i+1]-k-a[i]){
					flag = false;
					break;
				}
				m -= a[i+1]-k-a[i];
			}
		}
		if(flag == false) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}