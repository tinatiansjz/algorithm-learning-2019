// 只有12种候选的答案
// abcabc...abc, acbacb...acb, bacbac...bac, bcabca...bca, cabcab...cab, cbacba...cba
// aaa.bbb.ccc., aaa.ccc.bbb., bbb.aaa.ccc., bbb.ccc.aaa., ccc.aaa.bbb., ccc.bbb.aaa.
// We can check each of them naively.
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<string> res;
int main(){
	// freopen("in.txt", "r", stdin);
	int n;
	string s, t;
	cin >> n >> s >> t;
	string str = "abc";
	do{
		string cur;
		for(int i = 0; i < n; i++) cur += str;
		res.push_back(cur);
		res.push_back(string(n, str[0])+string(n, str[1])+string(n, str[2]));
	}while(next_permutation(str.begin(), str.end()));
	for(int i = 0; i < res.size(); i++){
		string check = res[i];
		if(check.find(s) == string::npos && check.find(t) == string::npos){
			cout << "YES" << endl;
			cout << check << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}