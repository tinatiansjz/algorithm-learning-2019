// dp[i][j]表示前i天完成前j项任务所需的最小难度,i、j都是从0开始数。
// dp[i][j] = dp[i-1][k-1] + max{jobDifficulty[k],jobDifficulty[k+1],...,jobDifficulty[j]}    (i<=k<=j)
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        int num = jobDifficulty.size();
        vector<vector<int> > dp(d, vector<int>(num, INF));
        // initialize
        dp[0][0] = jobDifficulty[0];
        for(int j = 1; j < num; j++)
            dp[0][j] = max(dp[0][j-1], jobDifficulty[j]);
        
        for(int i = 1; i < d; i++){
            for(int j = i; j < num; j++){
                int tmpMax = -1;
                for(int k = j; k >= i; k--){
                    tmpMax = max(tmpMax, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i-1][k-1]+tmpMax);
                }
            }
        }
        return dp[d-1][num-1];
    }
};