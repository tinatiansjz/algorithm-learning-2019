#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int L, n;
const int maxn = 1000000;
int x[maxn];
void solve(){
    //计算最短时间
    int minT = 0;
    for (int i = 0; i < n; i++){
        minT = max(minT, min(x[i], L-x[i]));
    }
    //计算最长时间
    int maxT = 0;
    for(int i = 0; i < n; i++){
        maxT = max(maxT, max(x[i], L-x[i]));
    }
    printf("%d %d\n", minT, maxT);
}
int main(){
    freopen("POJ-1852_in.txt", "r", stdin);
    int N;
    cin >> N;
    while(N--){
        cin >> L >> n;
        for(int i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }
        solve();
    }
    return 0;
}
