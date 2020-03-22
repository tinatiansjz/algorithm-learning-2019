// 最长的回文序列长度 和 最长公共子序列 本质上是一个东西
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        string t(s.rbegin(), s.rend());
        vector<vector<int> > dp(len+1, vector<int>(len+1));
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len][len];
    }
};