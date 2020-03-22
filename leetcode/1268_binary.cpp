// 二分查找
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string query;
        auto iter_last = products.begin();
        vector<vector<string> > ans;
        for(const char& ch: searchWord){
            query += ch;
            auto iter_find = lower_bound(iter_last, products.end(), query);
            vector<string> selects(0);
            for(int i = 0; i < 3; i++){
                if (iter_find + i < products.end() && (*(iter_find + i)).find(query) == 0) {
                    selects.push_back(*(iter_find + i));
                }
            }
            ans.push_back(selects);
            iter_last = iter_find;
        }
        return ans;
    }
};
int main(){

    return 0;
}