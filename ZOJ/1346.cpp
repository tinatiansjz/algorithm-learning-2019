// ZOJ - 1346
// Number of types of topological sorting
// 2019/03/08   20:42
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int dp[(1<<16)+10];
int tot; // num of vertice
map<string, int> m;
struct node{
    int to, next;
    node(){}
    node(int a, int b):to(a), next(b){}
}edge[400];
int head[20];
int in[20];
int d;
void init(){
    tot = 0; d = 0;
    memset(dp, 0, sizeof(dp));
    memset(head, -1, sizeof(head));
    m.clear();
}
int getid(string s){
    if(m.count(s)) return m[s];
    else return m[s] = tot++;
}
void add(int u, int v){
    edge[d] = node(v, head[u]);
    head[u] = d++;
}
void check(int s){
    memset(in, 0, sizeof(in));
    for(int i = 0; i < tot; i++){
        if(s & (1<<i)) continue;
        for(int j = head[i]; j != -1; j = edge[j].next){
            int to = edge[j].to;
            in[to]++;
        } 
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) == 1){
        init();
        string s1, s2;
        for(int i = 0; i < n; i++){
            cin >> s1 >> s2;
            int u = getid(s1);
            int v = getid(s2);
            add(u, v);
        }
        dp[0] = 1;
        int bit = 1 << tot;
        for(int i = 0; i < bit; i++){
            check(i);
            for(int j = 0; j < tot; j++){
                if(in[j] == 0){
                    int k = 1 << j;
                    if(i & k) continue;
                    int tmp = i | (1<<j);
                    dp[tmp] += dp[i];
                }
            }
        }
        printf("%d\n", dp[bit-1]);
    }
    return 0;
}