//kangba
#include <bits/stdc++.h>

using namespace std;
#define maxn 1005

typedef struct EDGE{
    int to,next;
}Edge;
int center[maxn],diam[maxn];
int vis[maxn],head[maxn],par[maxn];
Edge edges[maxn<<1];

int dfs(int u,int p,int &d){
    vis[u] = 1;
    par[u] = u;
    int longest = d;
    int best = u;
    int dep = d+1;
    for(int i=head[u];i!=-1;i=edges[i].next){
        if(edges[i].to==p)continue;
        int tmp = dfs(edges[i].to,u,dep);
        par[edges[i].to] = u;
        if(dep>longest){
            best = tmp;
            longest = dep;
        }
        dep = d+1;
    }
    d = longest;
    return best;
}

void find(int u,int id){
    int dist = 0;
    int v = dfs(u,-1,dist);
    dist = 0;
    v = dfs(v,-1,dist);
    diam[id] = dist;
    for(int i=dist/2;i>0;i--)
        v = par[v];
    center[id] = v;
}

int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    while(cin>>n>>m){
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[i].next=head[u];
            edges[i+m].next=head[v];
            edges[i].to = v;
            edges[i+m].to = u;
            head[u] = i;
            head[v] = i+m;
        }

        int id = 0, longest = 0, best = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i])find(i,++id);
            if(best==0||longest<diam[id]){
                best = id;longest = diam[id];
            }
        }

        //merge
        int ans = longest;
        for(int i=1;i<=id;i++){
            if(i==best)continue;
            ans = max(ans,(diam[i]+1)/2+(ans+1)/2+1);
        }

        cout<<ans<<endl;
        for(int i=1;i<=id;i++){
            if(i==best)continue;
            cout<<center[i]<<" "<<center[best]<<endl;
        }

    }
    return 0;
}