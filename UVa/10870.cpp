#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int d, n, MOD;
const int maxd = 20;
int a[maxd];
int f[maxd];
struct mat{
	ll a[maxd][maxd];
	int l, r;
}T, I, pre;
mat operator * (mat X, mat Y){
	mat Z;
	Z.l = X.l; Z.r = Y.r;
	for(int i = 0; i < X.l; i++)
		for(int j = 0; j < Y.r; j++){
			Z.a[i][j] = 0;
			for(int k = 0; k < X.r; k++)
				Z.a[i][j] = (Z.a[i][j]+X.a[i][k]*Y.a[k][j]%MOD)%MOD;
		}
	return Z;
}
void init(){
	memset(T.a, 0, sizeof(T.a));
	memset(I.a, 0, sizeof(I.a));
	memset(pre.a, 0, sizeof(pre.a));
	T.l = T.r = d;
	for(int i = 0; i < d; i++) T.a[0][i] = a[i+1];
	for(int i = 1; i < d; i++) T.a[i][i-1] = 1;
	I.l = I.r = d;
	for(int i = 0; i < d; i++) I.a[i][i] = 1;
	pre.l = d; pre.r = 1;
	for(int i = 0; i < d; i++) pre.a[i][0] = f[d-i];
}
int main(){
	// freopen("in.txt", "r", stdin);
	while(scanf("%d%d%d", &d, &n, &MOD) == 3){
		if(!d && !n && !MOD) break;
		for(int i = 1; i <= d; i++) {scanf("%d", &a[i]); a[i] = a[i]%MOD;}
		for(int i = 1; i <= d; i++) {scanf("%d", &f[i]); f[i] = f[i]%MOD;}
		if(n <= d) {cout << f[n] << endl; continue;}
		init();
		n = n-d;
		while(n){
			if(n&1) I = I*T;
			n = n>>1;
			T = T*T;
		}
		pre = I*pre;
		cout << pre.a[0][0] << endl;
	}
	return 0;
}