// dp
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int dp[10100];
    int INF= 0x3f3f3f3f;
    int minTaps(int n, vector<int>& ranges) {
        memset(dp,INF,sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < ranges.size(); i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            for(int j = l; j <= r; j++){
                dp[j] = min(dp[j],dp[l]+1); 
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};