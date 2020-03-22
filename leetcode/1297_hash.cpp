// 方法三：滚动哈希 / Rabin-Karp 算法
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<int, int> occ;
        unordered_map<char, int> exist;
        int ans = 0, exist_cnt = 0;
        int rabin = 0, base = 26, base_mul = base;
        
        for (int i = 0; i < minSize - 1; ++i) {
            ++exist[s[i]];
            if (exist[s[i]] == 1) {
                ++exist_cnt;
            }
            rabin = ((LL)rabin * base + (s[i] - 97)) % mod;
            base_mul = (LL)base_mul * base % mod;
        }

        for (int i = minSize - 1; i < n; ++i) {
            ++exist[s[i]];
            if (exist[s[i]] == 1) {
                ++exist_cnt;
            }
            rabin = ((LL)rabin * base + (s[i] - 97)) % mod;
            if (i >= minSize) {
                --exist[s[i - minSize]];
                if (exist[s[i - minSize]] == 0) {
                    --exist_cnt;
                }
                rabin = (rabin - (LL)base_mul * (s[i - minSize] - 97) % mod + mod) % mod;
            }
            if (exist_cnt <= maxLetters) {
                ++occ[rabin];
                ans = max(ans, occ[rabin]);
            }
        }
        return ans;
    }
};