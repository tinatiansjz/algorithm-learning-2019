// slide window
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 2000+5;
char a[maxn][maxn];
int R[maxn][2]; // l, r
int C[maxn][2]; // l, r
int dR[maxn][maxn], dC[maxn][maxn]; // 点击每个点，增加的white row / white column的数量
int cnt = 0;
int n, k;
int blank = 0;
void pre(){
	memset(R, -1, sizeof(R));
	memset(C, -1, sizeof(C));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			if(a[i][j] == 'B'){
				if(~R[i][0]) R[i][1] = j;
				else {R[i][0] = R[i][1] = j;}
			}
		if(R[i][0] == -1 && R[i][1] == -1) blank++;
	}
	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++)
			if(a[i][j] == 'B'){
				if(~C[j][0]) C[j][1] = i;
				else {C[j][0] = C[j][1] = i;}
			}
		if(C[j][0] == -1 && C[j][1] == -1) blank++;
	}
}
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%s", a[i]);
	pre();
	// click point: (i, j) 		0 <= i, j <= n-k
	// i<=i'<=i+k-1	&& j<=j'<=j+k-1
	for(int i = 0; i <= n-k; i++){ // column
		// j = 0
		cnt = 0;
		for(int m = 0; m <= k-1; m++){ // row
			// i<=l,r<=i+k-1
			if(C[m][0] >= i && C[m][0] <= i+k-1 && C[m][1] >= i && C[m][1] <= i+k-1)
				cnt++;
		}
		dC[i][0] = cnt;
		for(int j = 1; j <= n-k; j++){
			if(C[j-1][0] >= i && C[j-1][0] <= i+k-1 && C[j-1][1] >= i && C[j-1][1] <= i+k-1)
				cnt--;
			if(C[j+k-1][0] >= i && C[j+k-1][0] <= i+k-1 && C[j+k-1][1] >= i && C[j+k-1][1] <= i+k-1)
				cnt++;
			dC[i][j] = cnt;
		}
	}
	for(int j = 0; j <= n-k; j++){ // row
		// i = 0
		cnt = 0;
		for(int m = 0; m <= k-1; m++){
			// j<=l,r<=j+k-1
			if(R[m][0] >= j && R[m][0] <= j+k-1 && R[m][1] >= j && R[m][1] <= j+k-1)
				cnt++;
		}
		dR[0][j] = cnt;
		for(int i = 1; i <= n-k; i++){
			if(R[i-1][0] >= j && R[i-1][0] <= j+k-1 && R[i-1][1] >= j && R[i-1][1] <= j+k-1)
				cnt--;
			if(R[i+k-1][0] >= j && R[i+k-1][0] <= j+k-1 && R[i+k-1][1] >= j && R[i+k-1][1] <= j+k-1)
				cnt++;
			dR[i][j] = cnt;
		}
	}
	int _max = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			_max = max(_max, dR[i][j]+dC[i][j]);
	cout << _max+blank << endl;
	return 0;
}