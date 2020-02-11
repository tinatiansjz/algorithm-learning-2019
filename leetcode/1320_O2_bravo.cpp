// 2020/02/11   23:12
// 时间优化 O(n^2)
// 我们再重新观察一下这三个维度信息，分别是：字母下标，左指的键位，右指的键位。
// 由于每次需要按下一个字母，左指键位或者右指键位必然有一个是这个字母的键位，因此字母下标也隐含着一个指头的键位信息，使用三个维度显然会有冗余，
// 我们可以重新设计一种新的状态：字母下标（可以代表第一个指头键位），另外一个指头的键位。
// 每次按下一个字母时，要么是字母下标所在的指头（第一个指头）移动，要么是另外一个指头移动。
// https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers/solution/qing-xi-tu-jie-qiao-miao-de-dong-tai-gui-hua-by-hl/
// dp[i][K]: dp[字母下标 (可知第一个手指键位)][第二个手指的键位]
// dp[i][K] = min(dp[i][K], dp[i-1][K]+dist(word[i-1], word[i]))
// dp[i][word[i-1]] = min(dp[i][word[i-1]], dp[i-1][K]+dist(K, word[i]))
#include <string>
#include <cstring>
#include <algorithm>
#define l(x) ((x)&1)
using namespace std;
class Solution {
public:
    int minimumDistance(string word) {
        int len = word.size();
        init();
        for(int i = 1; i < len; i++){
            int p = word[i]-'A';
            int pre = word[i-1]-'A';
            for(int j = 0; j < 26; j++){
                if(dp[l(i-1)][j] >= INF) continue;
                dp[l(i)][j] = min(dp[l(i)][j], dp[l(i-1)][j] + getdist(pre, p));
                dp[l(i)][pre] = min(dp[l(i)][pre], dp[l(i-1)][j] + getdist(j, p));
            }
            for(int j = 0; j < 26; j++) dp[l(i-1)][j] = INF;    
        }  
        int ans = INF;
        for(int j = 0; j < 26; j++)
            ans = min(ans, dp[l(len-1)][j]);
        return ans;
    }
private:
    static const int maxn = 300;
    const int INF = 0x3f3f3f3f;
    int dp[2][26];
    void init(){
        // memset(dp[1], INF, sizeof(dp[1]));
        for(int i = 0; i < 26; i++) dp[1][i] = INF;
    }
    int getdist(int a, int b){
        int xa = a/6, ya = a%6, xb = b/6, yb = b%6;
        return abs(xa-xb)+abs(ya-yb);
    }
};