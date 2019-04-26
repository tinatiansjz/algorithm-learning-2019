// Eular筛法可以保证每个合数只会被枚举到一次，时间复杂度为O(n)。当N越大时，其相对于Eratosthenes筛法的优势也就越明显。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e6+5;
bool isPrime[maxn];
vector<int> primeList;
int main(){
	// freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	memset(isPrime, 1, sizeof(isPrime));
	int primeCount = 0;
	for(int i = 2; i <= n; i++){
		if(isPrime[i]){
			primeCount++;
			// cout << primeCount << endl;
			primeList.push_back(i);
		}
		for(int j = 0; j < primeCount; j++){
			if((long long)i*primeList[j] > (long long)n) break;
			isPrime[i*primeList[j]] = false;
			if(i % primeList[j] == 0) break;
		}
	}
	printf("%d\n", primeCount);
	return 0;
}
/*
isPrime[] = true
primeList = []
primeCount = 0
For i = 2 .. N
	If isPrime[i] Then
		primeCount = primeCount + 1
		primeList[ primeCount ] = i
	End If 
	For j = 1 .. primeCount
		If (i * primeList[j] > N) Then
			Break
		End If
		isPrime[ i * primeList[j] ] = false
		If (i % primeList[j] == 0) Then
			Break
		End If
	End If
End For
*/