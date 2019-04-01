// https://www.cnblogs.com/cenariusxz/p/6703289.html
// 模拟
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 100+5;
int cnt[maxn];// cnt[i]:第i层元素个数
int h[maxn][maxn];
bool vis[maxn];// vis[i] = true: i is a leaf
int l[maxn]; // leaf
int d[maxn][maxn];// d[i][j]:the distance between Li and Lj
int fa[maxn]; // father
int tot = 0;
int N, M, K;
// N: the number of nodes
// M: the depth of the tree
// K: the number of leaves
inline void init(){
    memset(fa, -1, sizeof(fa));
    memset(d, -1, sizeof(d));
    memset(vis, 0, sizeof(vis));
}
void update(int s){
    int f = fa[s];
    for(int i = 1; i <= N; i++){
        if(i != s && d[s][i] != -1){
            d[f][i] = d[i][f] = d[i][s]-1;
        }
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &N, &M, &K);
    init();
    for(int i = 1; i <= M; i++) scanf("%d", &cnt[i]); // M:depth
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= cnt[i]; j++)
            scanf("%d", &h[i][j]);// h[i][j]:第i层第j个元素
    for(int i = 1, tmp; i <= K; i++){
        scanf("%d", &l[i]);
        vis[l[i]] = true;
    }
    for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++)
            scanf("%d", &d[l[i]][l[j]]);
    for(int q = M; q > 1; q--){ // q:level
        int s = q, f = q-1; // son, father
        int pos1 = 1, pos2 = 1;
        while(pos2 <= cnt[f] && vis[h[f][pos2]])
            pos2++;
        fa[h[s][pos1]] = h[f][pos2];
        while(pos1 <= cnt[s]){
            int l1 = h[s][pos1];
            if(pos1 == cnt[s]){
                update(l1);
                break;
            }else{
                int l2 = h[s][pos1+1];
                if(d[l1][l2] != 2){
                    update(l1);
                    pos2++;
                    while(pos2 <= cnt[f] && vis[h[f][pos2]]) pos2++;
                }
                fa[l2] = h[f][pos2];
                pos1++;
            }
        }
    }
    bool first = true;
    for(int i = 1; i <= N; i++){
        if(first){
            if(fa[i] == -1) printf("0");
            else printf("%d", fa[i]);
            first = false;
        }else{
            if(fa[i] == -1) printf(" 0");
            else printf(" %d", fa[i]);
        }
    }
    printf("\n");
    return 0;
}