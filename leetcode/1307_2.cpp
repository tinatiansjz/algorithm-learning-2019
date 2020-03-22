#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<char, int> rep;
    unordered_map<char, int> lead_zero;
    bool used[10];
    int carry[10];
    
public:
    bool dfs(const vector<string>& words, const string& result, int pos, int id, int len) {
        if (pos == len) {
            return carry[pos] == 0;
        }
        else if (id < words.size()) {
            int sz = words[id].size();
            if (sz < pos || rep[words[id][sz - pos - 1]] != -1) {
                return dfs(words, result, pos, id + 1, len);
            }
            else {
                char ch = words[id][sz - pos - 1];
                for (int i = lead_zero[ch]; i < 10; ++i) {
                    if (!used[i]) {
                        used[i] = true;
                        rep[ch] = i;
                        bool check = dfs(words, result, pos, id + 1, len);
                        used[i] = false;
                        rep[ch] = -1;
                        if (check) {
                            return true;
                        }
                    }
                }
            }
            return false;
        } else {
            int left = carry[pos];
            for (const string& word: words) {
                if (word.size() > pos) {
                    left += rep[word[word.size() - pos - 1]];
                }
            }
            
            carry[pos + 1] = left / 10;
            left %= 10;
            char ch = result[result.size() - pos - 1];
            if (rep[ch] == left) {
                return dfs(words, result, pos + 1, 0, len);
            } else if (rep[ch] == -1 && !used[left] && !(lead_zero[ch] == 1 && left == 0)) {
                used[left] = true;
                rep[ch] = left;
                bool check = dfs(words, result, pos + 1, 0, len);
                used[left] = false;
                rep[ch] = -1;
                return check;
            } else {
                return false;
            }
        }
    }
    
    bool isSolvable(vector<string>& words, string result) {
        memset(used, false, sizeof(used));
        memset(carry, 0, sizeof(carry));
        for (string& word: words) {
            if (word.size() > result.size()) {
                return false;
            }
            for (char& ch: word) {
                rep[ch] = -1;
                lead_zero[ch] = max(lead_zero[ch], 0);
            }
            if (word.size() > 1) {
                lead_zero[word[0]] = 1;
            }
        }
        for (char& ch: result) {
            rep[ch] = -1;
            lead_zero[ch] = max(lead_zero[ch], 0);
        }
        if (result.size() > 1) {
            lead_zero[result[0]] = 1;
        }
        return dfs(words, result, 0, 0, result.size());
    }
};