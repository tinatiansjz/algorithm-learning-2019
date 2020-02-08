#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
struct Edge{
    int from, to;
    Edge(int u, int v){
        from = u; to = v;
    }
};
vector<Edge> edges;
vector<int> G[maxn];
set<int> s;
vector<int> ans;
bool vis[maxn];
int tot;
void init(int n){
    for(int i = 0; i <= n; i++)
        G[i].clear();
    edges.clear();
    tot = 0;//edges.size()
    s.clear();
    memset(vis, 0, sizeof(vis));
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    init(n);
    for(int i = 0, u, v; i < m; i++){
        scanf("%d%d", &u, &v);
        edges.push_back(Edge(u,v));
        G[u].push_back(tot++);
        edges.push_back(Edge(v,u));
        G[v].push_back(tot++);
    }

    vis[1] = true; ans.push_back(1);
    for(int i = 0; i < G[1].size(); i++){
        int index = G[1].at(i);
        Edge e = edges[index];
        if(vis[e.to] == false){
            s.insert(e.to);
        }
    }
    while(!s.empty()){
        // printf("Hello\n");
        set<int>::iterator it= s.begin();
        int tmp = *it;
        s.erase(it);
        ans.push_back(tmp); vis[tmp] = true;
        for(int i = 0; i < G[tmp].size(); i++){
            int index = G[tmp].at(i);
            Edge e = edges[index];
            if(vis[e.to] == false){
                s.insert(e.to);
            }
        }
    }
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
        cout << " " << ans[i];
    cout << endl;
    return 0;
}