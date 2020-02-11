#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        int curSum = 0, pnt = 0;
        vector<vector<int> > ans;
        vector<int> state;
        dfs(candidates, target, curSum, pnt, state, ans);
        return ans;
    }
    void dfs(vector<int>& num, int tar, int curSum, int pnt, vector<int>& stat, vector<vector<int> >& ans){
    	if(curSum > tar) return;
    	if(pnt > num.size()) return;
    	if(curSum == tar){
    		ans.push_back(stat);
			return;
		}
		for(int i = pnt; i < num.size(); i++){
//			remove the duplicates
//			Let the same level not appear the same element.
			if(i > pnt && num[i] == num[i-1]) continue;
			
			stat.push_back(num[i]);
			curSum += num[i];
			dfs(num, tar, curSum, i+1, stat, ans);
			stat.pop_back();
			curSum -= num[i];
		}
	}
};

vector<int> a;
int n, target;
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &target);
	for (int i = 0, tmp; i < n; i++) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	Solution s;
	vector<vector<int> > ans = s.combinationSum2(a, target);
	for(int i = 0; i < ans.size(); i++){
		vector<int>& node = ans[i];
		for(int j = 0; j < node.size(); j++) printf("%d ", node[j]);
		printf("\n");
	}
	return 0;
} 
