// B - Serval and Toy Bricks (codeforces)
// CodeForces - 1153B
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100+5;
int front[maxn];
int _left[maxn];
int top[maxn][maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int n, m, h; scanf("%d%d%d", &n, &m, &h);
    for(int i = 0; i < m; i++) scanf("%d", &front[i]);
    for(int i = 0; i < n; i++) scanf("%d", &_left[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &top[i][j]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(top[i][j] == 0) continue;
            top[i][j] = min(front[j], _left[i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", top[i][j]);
        cout << endl;
    }
    return 0;
}