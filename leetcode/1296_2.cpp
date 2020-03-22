// 官方题解，更具C++特点
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> s;
        for (int num: nums) {
            ++s[num];
        }
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            int num = iter->first;
            int occ = iter->second;
            if (occ > 0) {
                auto it = next(iter);
                for (auto i = 1; i < k; ++i, ++it) {
                    if (it != s.end() && it->first == num + i && it->second >= occ) {
                        it->second -= occ;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};