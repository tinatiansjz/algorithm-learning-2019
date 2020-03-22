// https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/solution/rang-zi-fu-chuan-cheng-wei-hui-wen-chuan-de-zui-sh/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int len = s.size();
        vector<vector<int> > dp(len+1, vector<int>(len+1));
        for(int i = 1; i <= len; i++) dp[i][i] = 1;
        for(int i = len-1; i >= 1; i--){
            for(int j = i+1; j <= len; j++){
                if(s[i-1] == s[j-1]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return s.size() - dp[1][len];
    }
};