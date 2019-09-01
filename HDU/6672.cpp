// 打表！！！注意循环区间与余数！！！
// 因为没看清楚余数和分组，WA了好几发
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		ll n; 
		cin >> n;
		// cout << n << "\t";
		if(n == 1 || n == 2) {cout << "1" << endl; continue;}
		ll a = (n-2)/6+1;
		ll b = (n-2)%6;
		// cout << a << " " <<  b << endl;
		switch(b){
			case 0: cout << 3*a-2 << endl; break;
			case 1: cout << a-1 << endl; break;
			case 2: cout << (a-1)*6+3 << endl; break;
			case 3: cout << a-1 << endl; break;
			case 4: cout << 3*a << endl; break;
			case 5: cout << (a-1)*4+5 << endl; break;
		}
	}
	// a[1] = 1, a[2] = 1;
	// for(int i = 3; i <= 100; i++){ // n
	// 	for(int j = 1; j <= i-1; j++)
	// 		a[i] = (a[i]+a[j]*j)%i;
	// }
	// for(int i = 1; i <= 100; i++) cout << i << "\t" << a[i] << endl;
	return 0;
}