#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
class Solution {
private:
    unordered_map<char, int> proj;
    unordered_map<int, char> inv_proj;
    vector<vector<int> > eq; // eq[7][26]
    vector<bool> nonzero;
    vector<vector<char> > isneed; // characters that need to be decided in one phase
    void init(){
        eq.resize(7, vector<int>(26));
        nonzero.resize(26);
        isneed.resize(7);
        for(int i = 0; i < 26; i++) proj['A'+i] = -1;
        for(int i = 0; i < 10; i++) inv_proj[i] = '-';
    }
    bool check(int phase, int& inc){
        vector<int>& cur_eq = eq[phase];
        int sum = inc;
        for(int i = 0; i < 26; i++){
            if(cur_eq[i] == 0) continue;
            if(proj['A'+i] == -1) {
                cout << "Something wrong!" << " " << char('A'+cur_eq[i]) << endl;
            }
            sum += proj['A'+i] * cur_eq[i];
        }
        inc = sum/10;
        return (sum%10 == 0);
    }
    void dfs(int phase, int idx, int inc, bool& ans){ // inc - 进位
        if(ans) return;
        if(idx == isneed[phase].size()){
            if(!check(phase, inc)) return;
            ans = (phase == 6);
            dfs(phase+1, 0, inc, ans);
        }
        if (idx < 0 || idx >= isneed[phase].size()) return; // 很关键！！！debug了半天段错误
        char c = isneed[phase][idx];
        for(int i = 0; i < 10; i++){
            if(inv_proj[i] != '-') continue;
            if(i == 0 && nonzero[c-'A']) continue;
            inv_proj[i] = c;
            proj[c] = i;
            int tmpinc = inc;
            dfs(phase, idx+1, inc, ans);
            // 回溯
            inc = tmpinc;
            inv_proj[i] = '-';
            proj[c] = -1;
        }
    }
    // void debug(){
    //     // eq
    //     for(int i = 0; i < 7; i++){
    //         for(int j = 0; j < 26; j++)
    //             cout << eq[i][j] << " ";
    //         cout << endl;
    //     }
    //     // isneed
    //     for(int i = 0; i < 7; i++){
    //         for(int j = 0; j < isneed[i].size(); j++)
    //             cout << isneed[i][j] << " ";
    //         cout << endl;
    //     }
    // }
public:
    bool isSolvable(vector<string>& words, string result) {
        init();
        words.push_back(result);
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int unit = 1;
            if(i == words.size()-1)  unit  = -1;

            reverse(word.begin(), word.end());
            for(int j = 0; j < word.size(); j++){
                eq[j][word[j]-'A'] += unit;
                if(word.size() > 1 && j == word.size()-1) nonzero[word[j]-'A'] = true;
            }
        }
        unordered_set<char> us;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 26; j++){
                if(eq[i][j] == 0) continue;
                int c = 'A'+j;
                if(us.count(c)) continue;
                us.insert(c);
                isneed[i].push_back(c);
            }
        }
        bool ans = false;
        dfs(0, 0, 0, ans);
        return ans;
    }
};

Solution s;
int main(){
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<string> words;
    string result, tmp;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        words.push_back(tmp);
    }
    cin >> result;
    // cout << result << " " << words[0] << " " << words[1] << " " << words.size() << endl;
    if(s.isSolvable(words, result)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}