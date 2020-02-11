// 2020/02/08 19:36
// https://leetcode-cn.com/problems/jump-game-v/solution/dp-dong-tai-gui-hua-fei-chang-hao-li-jie-by-wu-bin/
// 遍历每个点的顺序：从矮到高遍历，然后记录每个点的可移动的最大步数。
// 动态转移方程为
// dp[i] = max(dp[可以去的阶梯])+1;
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> tmp;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++)
            tmp.push_back({arr[i], i}); // c++11
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size(); i++){
            int id = tmp[i][1], h = tmp[i][0];
            // left <-
            for(int j = id-1; j >= id-d && j >= 0; j--){
                if(arr[j] >= h) break;
                dp[id] = max(dp[j]+1, dp[id]);
            }
            // right ->
            for(int j = id+1; j <= id+d && j < n; j++){
                if(arr[j] >= h) break;
                dp[id] = max(dp[j]+1, dp[id]);
            }
        }
        int _max = 0;
        for(int i = 0; i < n; i++){
            // cout << dp[i] << " ";
            if(dp[i] > _max) _max = dp[i];
        }
        return _max+1;
    }
};