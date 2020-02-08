// 举例: 101 010
// KMP
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
string cur, s;
const int maxn = 1e6+5;
int f[maxn];
int getFail(string tmp){
	// cout << tmp << endl;
	int len = tmp.size();
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < len; i++){
		int j = f[i];
		while(j && tmp[i] != tmp[j]) j = f[j];
		f[i+1] = tmp[i] == tmp[j] ? j+1 : 0;
	}
	return f[len];
}
int main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(!i) {cur = s; continue;}
		int ns = s.size(), cs = cur.size(), len;
		// 一定要加上分界符#，以区别cur和next
		len = getFail(s + "#" + cur.substr(max(0, cs-ns), min(cs, ns)));
		len = min(len, ns);
		cur += s.substr(len, s.size()-len);
	}
	cout << cur << endl;
	return 0;
}