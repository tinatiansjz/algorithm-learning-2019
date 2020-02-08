//https://codeforces.com/contest/1092/problem/F
//kangba
#include <bits/stdc++.h>

using namespace std;

#define maxn 200005
#define ll long long
typedef struct EDGE{
	int from,to;
}Edge;
vector<Edge> edges;
vector<int> G[maxn];

ll cost[maxn],W[maxn],sum,a[maxn],mx;
int n;

void dfs(int u,int p){
	int Gs = G[u].size();
	cost[u] = 0;W[u] = a[u];
	for(int i=0;i<Gs;i++){
		Edge &e = edges[G[u][i]];
		if(e.to==p)continue;
		dfs(e.to,u);
		W[u] += W[e.to];
		cost[u] += cost[e.to]+W[e.to];
	}
}

void dfs2(int u,int p){
	int Gs = G[u].size();
	for(int i=0;i<Gs;i++){
		Edge &e = edges[G[u][i]];
		if(e.to==p)continue;
		cost[e.to] = cost[u]-2*W[e.to]+sum;
		mx = max(cost[e.to],mx);
		dfs2(e.to,u);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin>>n){
		int m = n-1;
		edges.clear();sum=0;
		for(int i=0;i<=n;i++)G[i].clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],sum+=a[i];
		for(int i=0,u,v,tot=0;i<m;i++){
			cin>>u>>v;
			edges.push_back((Edge){u,v});
			edges.push_back((Edge){v,u});
			G[u].push_back(tot++);
			G[v].push_back(tot++);
		}
		dfs(1,-1);
		mx = cost[1];
		dfs2(1,-1);
		cout<<mx<<endl;
	}
	return 0;
}
