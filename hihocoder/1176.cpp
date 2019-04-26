// 欧拉路判定
// 2019/04/17   11:37
// hihocoder 1176
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e4+5;
int deg[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v; scanf("%d%d", &u, &v);
        deg[u]++; deg[v]++;
    }
    int odd = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0){
            printf("Part\n");
            return 0;
        }
        if(deg[i]&1) odd++;
        if(odd > 2){
            printf("Part\n");
            return 0;
        }
    }
    printf("Full\n");
    return 0;
}