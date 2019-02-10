//Ananagrams, UVa 156
//2018/10/13    10:40
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string, int> cnt;
vector<string> words;

//将单词s进行“标准化”
string repr(const string& s){
    string ans = s;
    for(int i = 0; i < ans.length(); i++){
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    freopen("P114_in.txt", "r", stdin);
    int n = 0;
    string s;
    while(cin >> s){
        if(s[0] == '#') break;
        words.push_back(s);
        string r = repr(s);
        if(!cnt.count(r)) cnt[r] = 0;
        cnt[r]++;
    }
    set<string> ans;
    for (int i = 0; i < words.size(); i++){
        if(cnt[repr(words[i])] == 1) 
            ans.insert(words[i]);
    }
    for(set<string>::iterator it = ans.begin(); it != ans.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
