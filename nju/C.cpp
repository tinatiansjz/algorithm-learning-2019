// generalize: POJ 1240
#include <iostream>
#include <string>
using namespace std;
string pre, pos;
int cal(string pre, string pos){
	// if(pre == "" && pos == "") return 1;
	if(pre.size() == 0 && pos.size() == 0) return 1;
	if(pre.size() != pos.size()) return 0;
	if(pre[0] != pos[pos.size()-1]) return 0;
	if(pre.size() == 1 && pos.size() == 1) return 1;
	int ans = 0;
	for(int i = 0; i <= pre.size()-1; i++){
		ans += cal(pre.substr(1, i), pos.substr(0, i)) // lchild
			* cal(pre.substr(i+1, pre.size()-i-1), pos.substr(i, pos.size()-i-1)); // rchild
	}
	return ans;
}
int main(){
	// freopen("in.txt", "r", stdin);
	cin >> pre >> pos;
	cout << cal(pre, pos) << endl;
	return 0;
} 