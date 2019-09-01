// NOI 3528
// 栈 O(n)
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int maxn = 100+5;
int k;
string a;
int ans[maxn], cnt = 0;
stack<int> s;
int main(){
	int T; cin >> T;
	while(T--){
		cin >> a;
		cin >> k;
		int bak = k;
		int n = a.size();
		if(n == k){
			cout << "0" <<endl;
			continue;
		}
		while(!s.empty()) s.pop();
		cnt = 0;
		for(int i = 0; i < n; i++){
			while(!s.empty() && k && s.top() > (int)(a[i]-'0')){
				s.pop(); k--;
			}
			s.push(a[i]-'0');
		}
		while(!s.empty()){
			ans[cnt++] = s.top();
			s.pop();
		}
		int tmp = 0;
		for(int i = cnt-1; i >= 0; i--){
			printf("%d", ans[i]);
			tmp++;
			if(tmp == n-bak) break;
		}
		cout << endl;
	}	
	return 0;
} 

