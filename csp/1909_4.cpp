// https://blog.csdn.net/richenyunqi/article/details/101396817#commentBox
// 收获: 
// 1. s.insert() 返回值为pair (first: iterator, second: bool)
// 2. unordered_map v.s. map
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;
struct Commodity{
	ll id, score;
	Commodity(ll id, ll score) : id(id), score(score) {}
	bool operator < (const Commodity& rhs) const{
		return score > rhs.score || (score == rhs.score)&&(id < rhs.id);
	}
};
const ll mul = 1e9; 
int main(){
	// freopen("in.txt", "r", stdin);
	int m, n; scanf("%d%d", &m, &n);
	set<Commodity> commodities;
	unordered_map<ll, set<Commodity>::iterator> um; // 存储商品id和对应的set中的迭代器
	vector<int> K(m);  //存储每类商品被选中的最多件数
	for(int i = 0, id, score; i < n; i++){
		scanf("%d%d", &id, &score);
		for(int j = 0; j < m; j++){
			ll ID = 1LL*j*mul+id;
			um[ID] = commodities.insert(Commodity(ID, score)).first;
		}
	}
	int opnum, op; scanf("%d", &opnum);
	while(opnum--){
		scanf("%d", &op);
		if(op == 1){
			int t, c, s; scanf("%d%d%d", &t, &c, &s);
			ll ID = 1LL*t*mul+c;
			um[ID] = commodities.insert(Commodity(ID, s)).first;
		}else if(op == 2){
			int t, c; scanf("%d%d", &t, &c);
			commodities.erase(um[1LL*t*mul+c]);
		}else{ // op == 3
			int k; scanf("%d", &k);
			for(int i = 0; i < m; i++) scanf("%d", &K[i]);
			vector<vector<int> > ans(m);
			for(auto& i : commodities){
				int t = i.id/mul;
				if(ans[t].size() < K[t]){
					ans[t].push_back(i.id%mul);
					k--;
					if(k <= 0) break;
				}
			}
			for(auto& i : ans){
				if(i.empty()) printf("-1\n");
				else{
					sort(i.begin(), i.end());
					for(auto j : i) printf("%d ", j);
					printf("\n");
				}
			}

		}
	}
	return 0;
}