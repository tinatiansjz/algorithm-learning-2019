// 将a0...an-1升序排列，b0...bn-1降序排列，对应相乘的结果一定是最小的
// 但注意的是，不需要将ai和bi真正排完，只需要两两对应即可
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
bool vis[maxn];
struct Graph{
    int top;
    struct Vertex{
        int head;
    }V[maxn];
    struct Edge{
        int v, next;
    }E[maxn];
    void init(){
        memset(V, -1, sizeof(V));
        top = 0;
    }
    void add_adge(int u, int v){
        E[top].v = v;
        E[top].next = V[u].head;
        V[u].head = top++;
    }
};
Graph g;
int cyc = 0; // the number of cycles
void dfs(int u){
    if(vis[u]){
        cyc++; return;
    }
    vis[u] = true;
    for(int i = g.V[u].head; ~i; i = g.E[i].next){
        dfs(g.E[i].v);
    }
}
struct Node{
    int val, id1, id2;
}a[maxn], b[maxn];
bool acsend(Node a, Node b){
    return a.val < b.val;
}
bool descend(Node a, Node b){
    return a.val > b.val;
}
bool cmp(Node a, Node b){
    return a.id1 < b.id1;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    g.init();
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].val);
        a[i].id1 = i;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i].val);
        b[i].id1 = i;
    }
    sort(a, a+n, acsend);
    sort(b, b+n, descend);
    for(int i = 0; i < n; i++) a[i].id2 = i;
    for(int i = 0; i < n; i++) b[i].id2 = i;
    sort(a, a+n, cmp);
    sort(b, b+n, cmp);
    for(int i = 0; i < n; i++)
        g.add_adge(a[i].id2, b[i].id2);
    for(int i = 0; i < n; i++)
        if(!vis[i]) dfs(i);
    printf("%d\n", n-cyc);
    return 0;
}
