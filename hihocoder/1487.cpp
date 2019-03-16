#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000+5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
bool vis[maxn][maxn];
int fa[maxn*maxn];
int cnt = 0;
int L = 0;
int S = 0;
int find(int a){
    return a == fa[a] ? a : fa[a] = find(fa[a]);
    // return fa[a] == -1 ? a : fa[a] = find(fa[a]);
}
void init(){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= maxn*maxn; i++) fa[i] = i;
    // memset(fa, 0xff, sizeof(fa));
}
int main(){
    freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    init();
    for(int i = 1; i <= n; i++){
        int x, y; scanf("%d%d", &x, &y);
        int id1 = x*maxn+y, cnt = 0;
        vis[x][y] = true;
        for(int j = 0; j < 4; j++){
            int nx = x+dx[j], ny = y+dy[j];
            if(nx < 0 || nx >= maxn || ny < 0 || ny >= maxn || !vis[nx][ny]) continue;
            int id2 = nx*maxn+ny;
            int fa1 = find(id1), fa2 = find(id2);
            if(fa1 != fa2){// 必须加此判断，否则S会被多剪
                           // 如果fa[n] == -1 为判断根节点条件的话，不加此判断，find()有时会没有递归出口，造成MLE
                fa[fa1] = fa2;
                if(cnt > 0) S--;
            }
            cnt++;
        }
        if(cnt == 0){S++; L += 4;}
        else if(cnt == 1){L += 2;}
        else if(cnt == 3){L -= 2;}
        else if(cnt == 4){L -= 4;}
        printf("%d %d %d\n", S, i, L);
    }
    return 0;
}
