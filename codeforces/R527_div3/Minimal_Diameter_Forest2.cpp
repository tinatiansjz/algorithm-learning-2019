//https://codeforces.com/contest/1092/problem/E
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1005;

int n, m;
vector<int> adj[MAX_N];//adjacent matrix

bool vis[MAX_N];//visit

int rad[MAX_N];
int diam[MAX_N];//diameter
int center[MAX_N];

int par[MAX_N];//parent
int dist[MAX_N];//distance

// returns idx of furthest node
int dfs(int u, int p, int d) {
    vis[u] = true;
    dist[u] = d;

    int best = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        int cur = dfs(v, u, d + 1);
        par[v] = u;
        if (dist[cur] > dist[best]) best = cur;
    }

    return best;
}

void find_radius(int u, int c) {
    int v = dfs(u, -1, 0);
    memset(dist, 0, sizeof(dist));
    int v2 = dfs(v, -1, 0);
    diam[c] = dist[v2];
    rad[c] = (dist[v2] + 1) / 2;
    for (int i = 0; i < rad[c]; ++i) {
        v2 = par[v2];
    }
    center[c] = v2;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cc = 0;
    int biggest = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++cc;
            find_radius(i, cc);
            if (biggest == 0 || rad[cc] > rad[biggest]) {
                biggest = cc;
            }
        }
    }

    int best = 0;
    for (int a = 1; a <= cc; ++a) {
        best = max(best, diam[a]);
    }

    for (int a = 1; a <= cc; ++a) {
        if (a == biggest) continue;
        best = max(best, 1 + rad[biggest] + rad[a]);
    }

    for (int a = 1; a <= cc; ++a) {
        for (int b = 1; b <= cc; ++b) {
            if (a == biggest || b == biggest) continue;
            if (a == b) continue;
            best = max(best, 2 + rad[a] + rad[b]);
        }
    }

    printf("%d\n", best);
    for (int a = 1; a <= cc; ++a) {
        if (a != biggest) {
            printf("%d %d\n", center[biggest], center[a]);
        }
    }

    return 0;
}