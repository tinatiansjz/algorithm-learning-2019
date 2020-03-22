// f[i][j]: 以 (i, j) 为右下角的正方形的最大边长
// f[i][j] = x 同样表示以 (i, j) 为右下角的正方形的数目为 x（即边长为 1, 2, ..., x 的正方形各一个）
// f[i][j] = matrix[i][j], if i == 0 or j == 0
//           0, if matrix[i][j] = 0
//           min(f[i][j-1], f[i-1][j], f[i-1][j-1]), otherwise
// (same idea as 221.cpp)
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) {dp[i][j] = 0; continue;}
                if(i == 0 || j == 0) {dp[i][j] = 1; res++; continue;}
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                res += dp[i][j];
            }
        }
        return res;
    }
};