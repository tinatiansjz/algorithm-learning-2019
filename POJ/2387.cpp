#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1000+10;
struct Edge{
    int from, to, dist;
    Edge(int u, int v, int d):from(u),to(v),dist(d){}
};
struct SPFA{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn]; //s到各个点的距离
    int p[maxn]; //最短路中的上一条弧
    int inq[maxn]; //对应节点是否在队列里面
    int cnt[maxn]; //对应节点被加到队列里面的次数
    void init(int n){
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));
    }
    void AddEdge(int from, int to, int dist){
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }
    bool bellman_ford(int s){
        queue<int> Q;
        for(int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        inq[s] = true;
        Q.push(s);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for(int i = 0; i < G[u].size(); i++){
                Edge& e = edges[G[u][i]];
                if(d[u] < INF && d[e.to] > d[u]+e.dist){
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if(!inq[e.to]){
                        Q.push(e.to); inq[e.to] = true;
                        if(++cnt[e.to] > n)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
int main(){
    // freopen("in.txt", "r", stdin);
    int T, N; scanf("%d%d", &T, &N);
    SPFA spfa; spfa.init(N);
    for(int i = 0; i < T; i++){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        spfa.AddEdge(u, v, w); spfa.AddEdge(v, u, w);
    }
    int flag = spfa.bellman_ford(N-1);
    cout << spfa.d[0] << endl;
    return 0;
}