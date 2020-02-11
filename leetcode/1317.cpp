#include <vector>
using namespace std;
class Solution {
public:
    bool check(int n){
        while(n){
            int t = n%10;
            if(t==0) return true;
            n/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> q;
        for(int i=1;i<=n;++i){
            if(check(i)) continue;
            if(check(n-i))  continue;
            q.push_back(i);
            q.push_back(n-i);
            return q;
        }
        return q;
    }
};