#include <cstring>
using namespace std;

const int maxn = 1e5+5;
int tot = 0;
bool vis[maxn];
int head[maxn];
struct edges{
    int v, next;
}E[maxn << 1];
void init(){
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    tot = 0;
}
void add_edge(int u, int v){
    E[tot].v = v; E[tot].next = head[u];
    head[u] = tot;
    tot++;
}

void dfs(int x){
    vis[x] = true;
    for(int i = head[x]; ~i; i = E[i].next){
        int y = E[i].v;
        if(vis[y]) continue;
        dfs(y);
    }
}

int main(){
    return 0;
}