#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define maxn 100005
typedef struct EDGE{
    int from,to,dis;
    EDGE(){}
    EDGE(int u,int v,int w){
        from=u;to=v;dis=w;
    }
}Edge;
vector<Edge> edges;
vector<int> G[maxn];
int tot;
void init(int n){
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
    edges.clear();
    tot = 0;//edges.size()
}

bool cmp(Edge e1,Edge e2){
    return e1.dis<e2.dis;
}

int fa[maxn];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    // int T; cin>>T;
    int n;
    int m;
    while(cin>>n&&n){
        m = n*(n-1)/2;
        init(n);
        for(int i=0,u,v,w;i<m;i++){
            cin>>u>>v>>w;
            edges.push_back(Edge(u,v,w));
            // edges.push_back(Edge(v,u,w));
            // G[u].push_back(tot++);
            // G[v].push_back(tot++);
        }
        sort(edges.begin(),edges.end(),cmp);
        for(int i=0;i<=n;i++)fa[i]=i;
        int ans = 0;
        for(int i=0;i<m;i++){
            Edge &e = edges[i];
            int tofa = find(e.to);
            int fromfa = find(e.from);
            if(tofa==fromfa)continue;
            fa[tofa]=fromfa;
            ans += e.dis;
        }
        cout<<ans<<endl;
    }
    return 0;
}