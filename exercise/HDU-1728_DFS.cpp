//HDU-1728  逃离迷宫
//2018/10/21 20:38
//DFS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100;
char pic[maxn][maxn];
int visited[maxn][maxn][10][4];
int m, n, k, x1, y1, x2, y2;
//  0       1       2       3
//(-1, 0) (0, 1) (1, 0) (0, -1)
int knext[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool flag = false;
void dfs(int r, int c, int dir, int turn){
    if(flag) return;
    int change = turn+1;
    // printf("r=%d,c=%d,dir=%d,turn=%d\n", r, c, dir, turn);
    if(r < 0 || r >= m || c < 0 || c >= n || turn > k) return;
    if((dir >= 0 && visited[r][c][turn][dir] >= 0) || pic[r][c] == '*') return;
    if(dir >= 0) visited[r][c][turn][dir] = 0;
    if(r == y2-1 && c == x2-1 && turn <= k){
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++){
        if(i == dir)
            dfs(r+knext[i][0], c+knext[i][1], i, turn);
        else
            dfs(r+knext[i][0], c+knext[i][1], i, change);
    }
}
int main(){
    // freopen("HDU-1728_in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for (int i = 0; i < m; i++){
            scanf("%s", pic[i]);
        }
        cin >> k >> x1 >> y1 >> x2 >> y2;
        memset(visited, -1, sizeof(visited));
        flag = false;
        dfs(y1-1, x1-1, -1, -1);
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
