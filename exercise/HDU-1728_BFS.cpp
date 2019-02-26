//HDU-1728  逃离迷宫
//BFS
//2018/10/21 23:24
#include <iostream>
#include <queue>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
char pic[maxn][maxn];
int visited[maxn][maxn][4];
int m, n, k, x1, y1, x2, y2;
//  0       1       2       3   <- dir
//(-1, 0) (0, 1) (1, 0) (0, -1)
int next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool flag = false;
struct Node{
    int r;
    int c;
    int turn;
    int dir;
    Node(int r=0, int c=0, int turn=0, int dir=0):\
        r(r),c(c),turn(turn),dir(dir) {}
};
Node walk(const Node& u, int i){
    int dir = u.dir;
    int turn = u.turn;
    if(dir != i) turn++;
    return Node(u.r+next[i][0], u.c+next[i][1], turn, i);
}
bool inside(int r, int c){
    return (r >= 0 && r< m && c >= 0 && c < n);
}
void bfs(){
    queue<Node> q;
    int r1, c1, dir1;
    for(int i = 0; i < 4; i++){
        r1 = y1 + next[i][0];
        c1 = x1 + next[i][1];
        dir1 = i;
        visited[r1][c1][dir1] = 1;
        q.push(Node(r1, c1, 0, dir1));
    }
    while(!q.empty()){
        Node u = q.front(); q.pop();
        if(u.r == y2 && u.c == x2 && u.turn <= k){
            flag = true;
            return;
        }
        for(int i = 0; i < 3; i++){
            Node v = walk(u, i);
            if(inside(v.r, v.c) && v.turn <= k && visited[v.r][v.c][i] < 0){
                visited[v.r][v.c][i] = 1;
                q.push(v);
            }
        }
    }
}
int main(){
    freopen("HDU-1728_in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for (int i = 0; i < m; i++){
            scanf("%s", pic[i]);
        }
        cin >> k >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        memset(visited, -1, sizeof(visited));
        flag = false;
        bfs();
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
