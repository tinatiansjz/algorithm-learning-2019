#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    static const int mod = 1e9+7;
    int numWays(int steps, int arrLen) {
        // 注意到在 steps 次操作后，指针的位置其实并不会超过 steps，因此可以将数组的长度置为 arrLen 和 steps + 1 中的较小值，
        // 这样就减少了动态规划的时间复杂度。
        arrLen = min(steps, arrLen); 
        vector<vector<int> > dp(2, vector<int>(arrLen));
        dp[1][0] = 1; dp[1][1] = 1; // step 1
        for(int j = 2; j <= steps; j++){         
            for(int i = arrLen-1; i >= 0; i--){
                if(i == arrLen-1){dp[j&1][i] = (dp[(j-1)&1][i]+dp[(j-1)&1][i-1])%mod; continue;}
                if(i == 0){dp[j&1][i] = (dp[(j-1)&1][i]+dp[(j-1)&1][i+1])%mod; continue;}
                dp[j&1][i] = ((dp[(j-1)&1][i-1]+dp[(j-1)&1][i])%mod + dp[(j-1)&1][i+1])%mod;
            }
            for(int i = 0; i < arrLen; i++) dp[(j-1)&1][i] = 0;
            // for(int k = 0; k < arrLen; k++) cout << dp[j&1][k] << " ";
            // cout << endl;
        }
        return dp[steps&1][0];
    }
};