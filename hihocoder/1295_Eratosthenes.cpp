#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6+5;
bool isPrime[maxn];
int main(){
	// freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	// cout << n <<endl;
	int primeCount = 0;
	memset(isPrime, 1, sizeof(isPrime));
	for(int i = 2; i <= n; i++){
		if(isPrime[i]){
			primeCount++;
			// cout << primeCount <<endl;
			long long multiple = 1LL*i*i;
			while(multiple <= (long long)n){
				isPrime[multiple] = false;
				multiple += i;
			}
		}
	}
	printf("%d\n", primeCount);
	return 0;
}
/*
isPrime[] = true
primeCount = 0
For i = 2 .. N
	If isPrime[i] Then
		primeCount = primeCount + 1
		multiple = 2
		While (i * multiple ≤ N)
			isPrime[i * multiple] = false
			multiple = multiple + 1
		End While 
	End If
End For
*/