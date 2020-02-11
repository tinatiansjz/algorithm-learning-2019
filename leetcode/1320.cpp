// 2020/02/11  16:52 PM
// 内存优化：滚动数组思想
// dp[i][L][R]: dp[字母下标][左指的键位][右指的键位]
// dp[i][c][r] = min(dp[i][c][r], dp[i-1][l][r] + dist(l, c))
// dp[i][l][c] = min(dp[i][l][c], dp[i-1][l][r] + dist(r,c))
// O(n^3)
class Solution {
public:
    int minimumDistance(string word) {
        init();
        for(int i = 0; i < 26; i++){
            dp[0][i][word[0]-'A'] = 0;
            dp[0][word[0]-'A'][i] = 0;
        }
        int len = word.size();
        for(int i = 1, c; i < len; i++){
            c = word[i]-'A';
            for(int l = 0; l < 26; l++){
                for(int r = 0; r < 26; r++){
                    dp[i][c][r] = min(dp[i][c][r], dp[i-1][l][r]+getdist(l,c));
                    dp[i][l][c] = min(dp[i][l][c], dp[i-1][l][r]+getdist(r,c));
                }
            }
        }
        int ans = INF;
        for(int l = 0; l < 26; l++)
            for(int r = 0; r < 26; r++)
                ans = min(ans, dp[len-1][l][r]);
        // debug(len-1);
        return ans;
    }
private:
    static const int maxn = 300;
    const int INF = 0x3f3f3f3f;
    int dp[maxn][26][26];
    void init(){
        memset(dp, INF, sizeof(dp));
    }
    int getdist(int a, int b){
        int xa = a/6, ya = a%6, xb = b/6, yb = b%6;
        return abs(xa-xb)+abs(ya-yb);
    }
};