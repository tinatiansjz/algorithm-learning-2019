// https://blog.csdn.net/ditian1027/article/details/21132583
// POJ 1240
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#define ll long long
using namespace std;
vector<int> v;
string pre, pos;
ll factorial(int n){
	ll ans = 1;
	for(ll i = 2; i <= n; i++) ans *= i;
	return ans;
}
ll C(int m, int n){ // C_n^m
	ll ans = 1;
	for(ll i = n; i >= n-m+1; i--) ans *= i;
	return ans/factorial(m);
}
void branch(int pre1, int pre2, int pos1, int pos2){
	// pre-order: [pre1, pre2], post-order: [pos1, pos2] 标注了两段的起始位置
	if(pre1 == pre2) return; //the leaf (no child/branch)
	int p1 = pre1+1, p2 = pos1;
	int cnt = 0; // amount of branches
	while(p2 < pos2){
		int len = 0;
		while(pre[p1] != pos[p2+len] && (p2+len < pos2)) len++;
		cnt++;
		branch(p1, p1+len, p2, p2+len);
		p1 = p1+len+1;
		p2 = p2+len+1;
		len = 0;
	}
	v.push_back(cnt);
}
int main(){
	// freopen("in.txt", "r", stdin);
	int m;
	while(cin >> m >> pre >> pos){
		if(m == 0) break;
		v.clear();
		branch(0, pre.size()-1, 0, pos.size()-1);
		ll ans = 1;
		// cout << v.size() << endl;
		for(int i = 0; i < v.size(); i++){
			int b = v[i];
			ans *= 1LL*C(b, m); 
		}
		cout << ans << endl;
	}
	return 0;
}