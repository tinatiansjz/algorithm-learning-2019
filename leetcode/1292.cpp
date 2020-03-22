// dp + 二分
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1));
        // cout << m << " " << n << endl;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j<= n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int l = 0, r = min(n, m);
        while(l < r){
            int mid = (l+r+1)/2;
            if(!check(mid, dp, threshold)) r = mid-1;
            else l = mid;
        }
        return l;
    }
    bool check(int s, vector<vector<int> >& dp, int threshold){
        int tmp;
        int m = dp.size()-1, n = dp[0].size()-1;
        for(int i = 1; i+s-1 <= m; i++){
            for(int j = 1; j+s-1 <= n; j++){
                tmp = dp[i+s-1][j+s-1]-dp[i+s-1][j-1]-dp[i-1][j+s-1]+dp[i-1][j-1];
                if(tmp <= threshold) return true;
            }
        }
        return false;
    }
};