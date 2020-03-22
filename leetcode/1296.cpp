#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(!mp.count(nums[i])) mp[nums[i]] = 1;
            else mp[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp[nums[i]] == 0) continue;
            for(int j = 0; j < k; j++){
                if(mp.count(nums[i]+j) == 0) return false;
                mp[nums[i]+j]--;
            }
        }
        return true;
    }
};