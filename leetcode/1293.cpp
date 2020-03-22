#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
    int r, c, res, depth;
    Node(int r=0, int c=0, int res=0, int depth=0): r(r), c(c), res(res), depth(depth) {}
};
class Solution {
public:
    static const int maxn = 40;
    int _next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = min(m+n-1, k); // clever!
        bool vis[m][n][k+1];
        memset(vis, 0, sizeof(vis)); // must!
        // bfs
        queue<Node> q;
        q.push(Node(0, 0, k, 0));
        vis[0][0][k] = true;
        int r1, c1;
        while(!q.empty()){
            Node u = q.front(); q.pop();
            if(u.r == m-1 && u.c == n-1){
                return u.depth;
            }
            for(int i = 0; i < 4; i++){
                r1 = u.r+_next[i][0];
                c1 = u.c+_next[i][1];
                if(r1 < 0 || r1 >= m || c1 < 0 || c1 >= n) continue;
                if(grid[r1][c1]){
                    if(u.res > 0){
                        if(vis[r1][c1][u.res-1]) continue;
                        vis[r1][c1][u.res-1] = true;
                        q.push(Node(r1, c1, u.res-1, u.depth+1));
                    }
                }else{
                    if(vis[r1][c1][u.res]) continue;
                    vis[r1][c1][u.res] = true;
                    q.push(Node(r1, c1, u.res, u.depth+1));
                }
            }
        }
        return -1;
    }
};