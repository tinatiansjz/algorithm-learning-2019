#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#define mp(x, y) make_pair(x, y)
using namespace std;
const int maxn = 2e5+5;
vector<int> v;
map<pair<int, int>, int> m; 
int a[maxn][2];
void cal(int n){
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			v.push_back(i);
			if(i*i != n) v.push_back(n/i);
		}
	}
}
bool judge(int q, int n, int p){
	for(int i = 0; i < p; i++){
		// cout << (a[i][0]+q)%n << " " <<(a[i][1]+q)%n <<endl;
		if(!m.count(mp((a[i][0]+q)%n, (a[i][1]+q)%n)) && !m.count(mp((a[i][1]+q)%n, (a[i][0]+q)%n))) return false;
	}
	return true;
}
int main(){
	// freopen("in.txt", "r", stdin);
	int n, p; scanf("%d%d", &n, &p); //cout << n << p <<endl;
	for(int i = 0; i < p; i++){
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][0]--; a[i][1]--;
		m[mp(a[i][0], a[i][1])] = 1;
	}
	v.clear();
	cal(n);
	for(int i = 0; i < v.size(); i++){
		if(v[i] == n) continue;
		if(judge(v[i], n, p)) {printf("Yes\n"); return 0;}
	}
	printf("No\n");
	return 0;
}