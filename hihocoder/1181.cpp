// Fleury算法求欧拉路径
// http://hihocoder.com/contest/hiho50/problem/1
// dfs clever!
// 2019/04/17   11:51
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000+5;
const int maxm = 5000+5;
int pathsize = 0;
int path[maxm];
struct Graph{
    int top;
    int head[maxn];
    int deg[maxn];
    struct edge{
        int v, next;
    }E[maxm];
    void init(){
        top = 0;
        memset(head, -1, sizeof(head));
    }
    void add_edge(int u, int v){
        E[top].v = v;
        E[top].next = head[u];
        head[u] = top;
        top++;
    }
    bool del_edge(int u, int v){
        int first = head[u];
        if(v == E[first].v){
            head[u] = E[first].next;
            return true;
        }
        int pre = first, p;
        while((p = E[pre].next) != -1){
            if(v == E[p].v){
                E[pre].next = E[p].next;
                return true;
            }
            pre = p; 
        }
        return false;
    }
};
Graph g;
void dfs(int u){
    while(g.head[u] != -1){
        int id = g.head[u];
        int v = g.E[id].v;
        g.del_edge(u, v);
        g.del_edge(v, u);
        dfs(v);
    }
    path[pathsize++] = u;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n, m; scanf("%d%d", &n, &m);
    g.init();
    for(int i = 0; i < m; i++){
        int u, v; scanf("%d%d", &u, &v);
        g.add_edge(u, v);
        g.add_edge(v, u);
        g.deg[u]++; g.deg[v]++;
    }
    int start = 1;
    for(int i = 1; i <= n; i++){
        if(g.deg[i]&1){start = i; break;}
    }
    dfs(start);
    printf("%d", path[0]);
    for(int i = 1; i < pathsize; i++)
        printf(" %d", path[i]);
    printf("\n");
    return 0;
}