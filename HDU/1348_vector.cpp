// HDU 1384 difference constraint
// 将 [0,n] 中的所有数字抽象成点，且 d[i] 表示区间 [0,i] 中包含的集合中数字的个数。
// 发现对于问题"区间 [a,b] 中包含的集合中相同数字的个数"，满足区间减法的性质，即d[b] - d[a-1]
// 从而对应住题目中的约束条件，即d[b] - d[a-1] >= ci，可以建边 a-1 -> b 权值为ci，再求最长路。
// 另外，对于此类题目，还需要挖掘出题目的隐含条件，对于此题，即 d[i] - d[i-1] >= 0 ，d[i] - d[i-1] <= 1。符号不一致的，转成负边再建边。
// 最后，还需要增加一个源点 s ，与所有点相连，边权为0，由于上面的隐含条件，此题就不需要连了。
// 不过还不清楚为什么要增加源点。增加源点，是为了防止图不连通。
// 小细节：由于 a-1 可能等于 -1，所以要把所有点映射成 +1 的点。
// https://blog.csdn.net/dgq8211/article/details/9319651
// spfa 最长路算法
// vector存储 耗空间 耗时 但是直观
// 3026ms 9168kB
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50000+10;
struct Edge{
    int from, to, dist;
    Edge(int u, int v, int d):from(u),to(v),dist(d){}
};
struct SPFA{
    int N, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn]; //s到各个点的距离
    int p[maxn]; //最短路中的上一条弧
    int inq[maxn]; //对应节点是否在队列里面
    int cnt[maxn]; //对应节点被加到队列里面的次数
    void init(){
        // this->n = n;
        for(int i = 0; i < N; i++) G[i].clear();
        edges.clear();
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));
    }
    void AddEdge(int from, int to, int dist){
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }
    bool bellman_ford(int s, int n){
        queue<int> Q;
        memset(d, -63, sizeof(d));
        d[s] = 0;
        inq[s] = true;
        Q.push(s);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for(int i = 0; i < G[u].size(); i++){
                Edge& e = edges[G[u][i]];
                if(d[e.to] < d[u]+e.dist){
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
    int T;
    while(scanf("%d", &T) == 1){
        SPFA spfa; spfa.init();
        int R = -INF, L = INF;
        for(int i = 0; i < T; i++){
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            a++; b++; R = max(R, b); L = min(L, a);
            //  d[b]-d[a-1] >= c;
            spfa.AddEdge(a-1, b, c);
        }
        spfa.N = R;
        // d[i]-d[i-1] >= 0; d[i-1]-d[i] >= -1
        for(int i = L; i <= R; i++){
            spfa.AddEdge(i-1, i, 0);
            spfa.AddEdge(i, i-1, -1);
        }
        spfa.bellman_ford(L-1, R-L+2);
        printf("%d\n", spfa.d[R]);
    }
    return 0;
}