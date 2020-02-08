// https://codeforces.com/blog/entry/69464
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int maxn = 2e5+5;
int a[maxn], b[maxn];
char ans[maxn];
set<int> s1, s2;
vector<int> v;
int main(){
	// freopen("in.txt", "r", stdin);
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {scanf("%d", &a[i]); a[i]--;}
	for(int i = 0; i < n; i++) {scanf("%d", &b[i]); b[i]--;}	
	for(int i = 0; i < n; i++){
		int p = a[i], q = b[i];
		if(s2.count(p))	s2.erase(p);
		else s1.insert(p);
		if(s1.count(q)) s1.erase(q);
		else s2.insert(q);
		if(s1.empty() && s2.empty()) v.push_back(i);
	}
	if(v.size() < k) {
		printf("NO\n");
	}else{
		printf("YES\n");
		int l = 0, r = 0;
		char cur = 'a';
		for(int i = 0; i < v.size(); i++){
			r = v[i];
			for(int j = l; j <= r; j++)
				ans[a[j]] = cur;
			cur = min(char(cur+1), 'z');
			l = r+1;
		}
		for(int i = 0; i < n; i++) printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}