#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
struct Edge{
    int from, to, dist;
    Edge(int u, int v, int d):from(u),to(v),dist(d){}
};
struct HeapNode{
    int d, u;
    bool operator < (const HeapNode rhs) const{
        return d > rhs.d || (d == rhs.d && u > rhs.u);
    }
};
struct Dijkstra{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn]; //是否永久标号
    int d[maxn]; //s到各个点的距离
    int p[maxn]; //最短路中的上一条弧

    void init(int n){
        this->n = n;
        for(int i = 1; i <= n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist){
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }
    void dijkstra(int s){
        priority_queue<HeapNode> Q;
        for(int i = 1; i <= n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){0, s});
        while(!Q.empty()){
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for(int i = 0; i < G[u].size(); i++){
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dist){
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
    }
};
int main(){
    // freopen("in.txt", "r", stdin);
    Dijkstra p, q;
    int N, M, X; scanf("%d%d%d", &N, &M, &X);
    p.init(N); q.init(N);
    for(int i = 0; i < M; i++){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        p.AddEdge(v, u, w);
        q.AddEdge(u, v, w);
    }
    p.dijkstra(X); q.dijkstra(X);
    int ans = -INF;
    for(int i = 1; i <= N; i++){
        if(p.d[i]+q.d[i] > ans) ans = p.d[i]+q.d[i];
    }
    cout << ans << endl;
    return 0;   
}