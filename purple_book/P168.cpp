// UVa 10305
// topological sorting
#include <iostream>
#include <cstring>
#include <cstdio>
const int maxn = 1000;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;
using namespace std;
// c[u]=0: 从来没有访问过
// c[u]=1: 已经访问过，并且还递归访问过它的所有子孙（即dfs(u)曾被调用过，并已返回）
// c[u]=-1: 正在访问（即递归调用dfs(s)正在栈中，尚未返回）
bool dfs(int u){
    c[u] = -1;
    for(int v = 0; v < n; v++)
        if(G[u][v]){
            if(c[v] < 0) return false;
            else if(c[v] == 0) dfs(v);
        }
    c[u] = 1; topo[--t] = u;
    return true;
}
bool toposort(){
    t = n;
    memset(c, 0, sizeof(c));
    for(int u = 0; u < n; u++)
        if(!c[u])
            if(!dfs(u))
                return false;
    return true;
}
int main(){
    while(scanf("%d%d", &n, &m) == 2 && n){
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v); u--; v--;
            G[u][v] = 1;
        }
        if(toposort()){
            for(int i = 0; i < n-1; i++)
                printf("%d ", topo[i]+1);
            printf("%d\n", topo[n-1]+1);
        }else{
            printf("No\n");
        }
    }
    return 0;
}
