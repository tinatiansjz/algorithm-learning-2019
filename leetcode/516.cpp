// longestPalindromeSubseq
// 2020/02/12
// dp[i][j]: 子串 s[i,...,j] 中最长的回文序列长度
// transfer:
// if(s[i] == s[j]): dp[i][j] = dp[i+1][j-1] + 2
// else dp[i][j] = max(dp[i+1][j], dp[i][j-1])
// 注意遍历顺序，i 从最后一个字符开始往前遍历，j 从 i + 1 开始往后遍历，这样可以保证每个子问题都已经算好
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int> > dp(len+1, vector<int>(len+1));
        for(int i = 1; i <= len; i++) dp[i][i] = 1;
        for(int i = len-1; i >= 1; i--){
            for(int j = i+1; j <= len; j++){
                if(s[i-1] == s[j-1]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[1][len];
    }
};