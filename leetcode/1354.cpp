// 逆向思维（操作可逆）
// 有意思~
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long tot=0;
    priority_queue<int>Q;
    bool isPossible(vector<int>& target) {
        if ((int)target.size()==1) return target[0]==1;
        while (!Q.empty()) Q.pop();
        for(auto x:target) Q.push(x),tot+=x;
        while (!Q.empty()){
            int x=Q.top();Q.pop();
            if (x==1) break;
            if (x*2-tot<1) return false;
            long long left=tot-x;
            long long y=Q.top();
            long long k;
            if (y==1) k=(x-y+left-1)/left;
            else k=(x-y)/left+1;
            x-=k*left;
            if (x<=0) return false;
            tot-=k*left;
            Q.push(x);
        }
        return true;
    }
};