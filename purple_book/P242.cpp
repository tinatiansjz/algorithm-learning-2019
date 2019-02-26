// UVa 1471 Defense Lines
// 单调队列
// 2019/2/4 18:05
#include <iostream>
#include <cstdio>
#include <set>
#include <cassert>
using namespace std;
struct Candidate{
    int a, g;
    Candidate(int a, int g):a(a),g(g) {}
    bool operator < (const Candidate& rhs) const{
        return a < rhs.a;
    }
};
set<Candidate> s;
const int maxn = 2e5+5;
int n, a[maxn], f[maxn], g[maxn];
int main(){
    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        if(n == 1) {cout << "1" << endl; continue;}
        // g[i] is the length of longest increasing continuous subsequence ending at i
        g[0] = 1;
        for(int i = 1; i < n; i++){
            if(a[i-1] < a[i]) g[i] = g[i-1]+1;
            else g[i] = 1;
        }
        // f[i] is the length of longest increasing continuous subsequence starting from i
        f[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(a[i] < a[i+1]) f[i] = f[i+1]+1;
            else f[i] = 1;
        }
        s.clear();
        s.insert(Candidate(a[0], g[0]));
        int ans = 1;
        for(int i = 1; i < n; i++){
            Candidate c(a[i], g[i]);
            set<Candidate>::iterator it = s.lower_bound(c);// first one that is >= c
            bool keep = true;
            if(it != s.begin()){
                Candidate last = *(--it); //(--it) points to the largest one that is > c
                int len = f[i] + last.g;
                ans = max(ans, len);
                if(c.g <= last.g) keep = false;
            }
            if(keep){
                s.erase(c);
                s.insert(c);
                it = s.find(c);
                it++;
                while(it != s.end() && it->a > c.a && it->g <= c.g) s.erase(it++);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
