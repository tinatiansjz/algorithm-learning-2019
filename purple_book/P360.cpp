#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
int first[maxn];
int u[maxn], v[maxn], w[maxn], next[maxn];
void read_graph(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) first[i] = -1;//初始化表头
    for(int e = 0; e < m; e++){
        scanf("%d%d%d", &u[e], &v[e], &w[e]);
        next[e] = first[u[e]];//插入链表
        first[u[e]] = e;
    }
}
int main(){
    return 0;
}
