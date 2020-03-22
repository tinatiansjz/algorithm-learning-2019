// f[i][j]: 字符串 S 的前 i 个字符，将它分割成 j 个非空且不相交的回文串，最少需要修改的字符数。状态转移时，枚举第 j 个回文串的起始位置 i0，那么就有如下的状态转移方程：

// f[i][j] = min(f[i0][j - 1] + cost(S, i0 + 1, i))
// 其中 cost(S, l, r) 表示将 S 的第 l 个到第 r 个字符组成的子串变成回文串，最少需要修改的字符数。cost(S, l, r) 可以通过双指针的方法求出
// 时间复杂度：O(K*N^3), 空间复杂度：O(NK)
// 经过预处理 [提前求出cost的值]
// 时间复杂度：O(K*N^2), 空间复杂度：O(NK+N^2)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {    
public:
    static const int INF = 0x3f3f3f3f;
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n+1, vector<int>(n+1));

// // 记 cost[l][r] = cost(S, l, r)
// // cost[l][r] = cost[l + 1][r - 1],       if S[l] == S[r]
// // cost[l][r] = cost[l + 1][r - 1] + 1,   if S[l] != S[r]
// // cost[l][r] = 0,                        if l >= r
        for (int span = 2; span <= n; ++span) {
            for (int i = 0; i <= n - span; ++i) {
                int j = i + span - 1;
                cost[i+1][j+1] = cost[i+2][j] + (s[i] == s[j] ? 0 : 1);
            }
        }
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0x3f3f3f3f));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= min(i, k); j++){
                for(int i0 = j-1; i0 < i; i0++){
                    dp[i][j] = min(dp[i][j], dp[i0][j-1]+cost[i0+1][i]);
                }
            }
        }
        return dp[n][k];
    }
    // int cost(string s, int l, int r){
    //     int a = l-1, b = r-1, ans = 0;
    //     while(a < b){
    //         if(s[a] != s[b]) ans++;
    //         a++; b--;
    //     }
    //     return ans;
    // }
};