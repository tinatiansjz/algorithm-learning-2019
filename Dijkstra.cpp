//https://blog.csdn.net/whereisherofrom/article/details/78922648
// 2019/1/17    11:10
#include <iostream>
#include <cstdio>
const int INF = 0x3f3f3f3f;
const int maxn = 1000;
int head[maxn];
int edgeCount;
struct EDGE{
    int u, v, w, next;
    EDGE() {}
    EDGE(int _u, int _v, int _w, int _next){
        u = _u, v = _v, w = _w, next = _next;
    }
}edge[MAXN];
void init(){
    memset(head, INF, sizeof(head));//初始化所有的head[i] = INF
    edgeCount = 0;
}
// 调用时只要通过head[i]就能访问到由i出发的第一条边的编号，通过编号到edge数组进行索引可以得到边的具体信息，根据这条边的next域可以得到第二条边的编号，以此类推，直到next域为INF
void addEdge(int u, int v, int w){
    edge[edgeCount] = EDGE(u, v, w, head[u]);
    head[u] = edgeCount++;//头插法 链式前向星
}
