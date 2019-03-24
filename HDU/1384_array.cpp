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
// 前向星存储 数组存储 时间更短
// 1653ms 3744kB
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 5e4+5;
const int maxm = 15e4+5;
struct Graph{
    int top;
    struct Vertex{
        int head;
    }V[maxn];
    struct Edge{
        int v,next;
        int w;
    }E[maxm];
    void init(){
        memset(V,-1,sizeof(V));
        top = 0;
    }
    void add_edge(int u,int v,int w){
        E[top].v = v;
        E[top].w = w;
        E[top].next = V[u].head;
        V[u].head = top++;
    }
};
Graph g;

int d[maxn];
int cnt[maxn];
bool inq[maxn];
bool spfa(int s,int n){
    memset(cnt, 0, sizeof(cnt));
    memset(inq, false, sizeof(inq));
    memset(d, -63, sizeof(d));
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    d[s] = 0;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        inq[u] = false;
        for(int i = g.V[u].head; ~i; i = g.E[i].next){
            int v = g.E[i].v;
            int w = g.E[i].w;
            if(d[u] + w > d[v]){
                d[v] = d[u] + w;
                if(!inq[v]){
                    Q.push(v);
                    inq[v] = true;
                    if(++cnt[v] > n) return false;
                }
            }
        }
    }
    return true;
}
 
int main(){
    // freopen("in.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) == 1){
        g.init();
        int L = 50005 , R = 0;
        for(int i = 0; i < n; i++){
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            a++; b++;
            L = min(L, a); R = max(R, b);
            g.add_edge(a-1, b, c);
        }
        for(int i = L; i <= R; i++){
            g.add_edge(i-1, i, 0);
            g.add_edge(i, i-1, -1);
        }
        spfa(L-1, R-L+2);
        printf("%d\n", d[R]);
    }
    return 0;
}