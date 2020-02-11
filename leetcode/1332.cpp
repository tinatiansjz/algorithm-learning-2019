// 2020-02-09
// Are subsequences composed of only one type of letter always palindrome strings ?
#include <string>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.size();
        if(len == 0) return 0;
        for(int i = 0; i <= len/2; i++)
            if(s[i] != s[len-1-i]) return 2;
        return 1;
    }
};