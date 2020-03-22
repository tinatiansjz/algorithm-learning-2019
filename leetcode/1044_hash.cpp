// 二分+哈希（Rabin-Karp 字符串编码）
#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    string longestDupSubstring(string S) {
        string ans;
        int len = S.size();
        int l = 0, r = len-1;
        while(l < r){
            // cout << l << " " << r << endl;
            int mid = (l+r+1)/2;
            if(!check(S, mid, ans)) r = mid-1;
            else l = mid;
        }
        check(S, l, ans);
        return ans;
    }
private:
    static const int mod = 1e9+7;
    static const int MOD = 0x3f3f3f3f;
    static const int base = 26;
    bool check(const string& S, int l, string& ans){
        unordered_set<int> us, US;
        ll bl = 1, BL = 1, encode = 0, ENCODE = 0;
        for(int i = 1; i <= l-1; i++){
            bl = (bl*base)%mod;
            BL = (BL*base)%MOD;
        }
        for(int i = 0; i < l; i++){
            encode = (encode*base%mod + (S[i]-'a')) % mod;
            ENCODE = (ENCODE*base%MOD + (S[i]-'a')) % MOD;
        }
        // cout << encode << " " << bl << endl;
        us.insert((int)encode);
        US.insert((int)ENCODE);
        for(int i = 1; i <= S.size()-l; i++){
            encode = (encode-(S[i-1]-'a')*bl%mod + mod) % mod;
            encode = (encode*base%mod + (S[i+l-1]-'a')) % mod;
            ENCODE = (ENCODE-(S[i-1]-'a')*BL%MOD + MOD) % MOD;
            ENCODE = (ENCODE*base%MOD + (S[i+l-1]-'a')) % MOD;
            // cout << encode << endl;
            if(us.count(encode) && US.count(ENCODE)){
                // cout << "Hello" << endl;
                ans = S.substr(i, l);
                return true;
            }
            us.insert((int)encode);
            US.insert((int)ENCODE);
        }
        return false;
    }
};