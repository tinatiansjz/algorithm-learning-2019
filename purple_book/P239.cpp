// UVa 11572
// sliding window
// 2018/12/25  18:51
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1e6 + 5;
int A[maxn];
int main(){
    freopen("P239_in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &A[i]);
        set<int> s;
        int L = 0, R = 0, ans = 0;
        while(R < n){
            while(R < n && !s.count(A[R])) s.insert(A[R++]);// span R
            ans = max(ans, R-L);
            s.erase(A[L++]);// increase L
        }
        printf("%d\n", ans);
    }
    return 0;
}