#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5+5;
char a[maxn];
int b[10];
int main(){
	// freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	scanf("%s", a);
	// cout << a << endl;
	for(int i = 0; i < n; i++){
		if(a[i] >= '0' && a[i] <= '9') b[a[i]-'0'] = 0;
		else if(a[i] == 'L'){
			for(int j = 0; j < 10; j++){
				if(b[j] == 0){
					b[j] = 1;
					break;
				}
			}
			// cout << b << endl;
		}else if(a[i] == 'R'){
			for(int j = 9; j > -1; j--){
				if(b[j] == 0){
					b[j] = 1;
					break;
				}
			}
		}
	}
	for(int i = 0; i < 10; i++)
		printf("%d", b[i]);
	cout << endl;
	return 0;
}