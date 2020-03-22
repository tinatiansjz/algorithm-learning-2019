// 方法一：枚举
// 方法二：可行性优化：在所有满足条件且出现次数最多的的字符串中，一定有一个的长度恰好为 minSize
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> occ;
        int ans = 0;
        for (int i = 0; i < n - minSize + 1; ++i) {
            string cur = s.substr(i, minSize);
            unordered_set<char> exist(cur.begin(), cur.end());
            if (exist.size() <= maxLetters) {
                string cur = s.substr(i, minSize);
                ++occ[cur];
                ans = max(ans, occ[cur]);
            }
        }
        return ans;
    }
};