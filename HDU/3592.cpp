// https://blog.csdn.net/stay_accept/article/details/51799831
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, d[1005], deg[1005], vis[1005];
struct node{
    int to, val;
};
vector<node> G[1005];
int spfa(int S){

}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < x; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(u > v) swap(u, v);
            G[u].push_back((node){v, w});// u < v
        }
        for(int i = 0; i < y; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(u > v) swap(u, v);
            G[v].push_back((node){u, -w});
        }
        printf("%d\n", spfa(1));
    }
}
