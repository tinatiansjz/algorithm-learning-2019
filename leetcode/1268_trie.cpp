// trie 字典树
// 时间复杂度：O(\sum{L} + S)
// 空间复杂度：O(\sum{L})
#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Trie{
    unordered_map<char, Trie*> child;
    // 存放字典序最小的三个以 prefix 为前缀的字符串
    priority_queue<string> words;
};
class Solution{
private:
    void addWord(Trie* root, const string& word){
        Trie* cur = root;
        for(const char& ch: word){
            if(!cur->child.count(ch)){
                cur->child[ch] = new Trie();
            }
            cur = cur->child[ch];
            cur->words.push(word);
            if(cur->words.size() > 3)
                cur->words.pop();
        }
    }
public:
    vector<vector<string> > suggestedProducts(vector<string>& products, string searchWord){
        Trie* root = new Trie();
        for(const string& word: products)
            addWord(root, word);
        
        vector<vector<string> > ans;
        Trie* cur = root;
        bool flag = false;
        for(const char& ch: searchWord){
            if(flag || !cur->child.count(ch)){
                ans.emplace_back(); // null vector
                flag = true;
            }else{
                cur = cur->child[ch];
                vector<string> selects(0);
                while(!cur->words.empty()){
                    selects.push_back(cur->words.top());
                    cur->words.pop();
                }
                reverse(selects.begin(), selects.end());
                ans.push_back(selects);
            }
        }
        return ans;
    }
};
int main(){
    freopen("in.txt", "r", stdin);
    return 0;
}