#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int n, m;
const int maxn = 1e5+10;
vector<int> E[maxn];
set<int> s;
bool vis[maxn];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v; scanf("%d%d", &u, &v);
        E[u].push_back(v); E[v].push_back(u);
    }
    s.insert(1);
    while(!s.empty()){
        set<int>::iterator it = s.begin();
        printf("%d ", *it);
        int u = *it; s.erase(it); vis[u] = 1;
        for(int i = 0; i < E[u].size(); i++){
            if(!vis[E[u][i]]) s.insert(E[u][i]);
        }
    }
    return 0;
}
