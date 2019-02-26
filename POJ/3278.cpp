// BFS + pruning (prevent duplicate access)
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
struct node{
    int n;
    int depth;
    node(int n, int depth):n(n), depth(depth) {}
};
bool visited[maxn];
queue<node> q;
void init(){
    memset(visited, false, sizeof(visited));
    while(!q.empty()) q.pop();
}
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N, K;
    cin >> N >> K;
    // cout << N << " " << K << endl;
    init();
    q.push(node(N, 0)); visited[N] = true;
    while(!q.empty()){
        node cur = q.front(); q.pop();
        if(cur.n == K) {
            cout << cur.depth << endl;
            break;
        }
        // cout << "cur: " << cur.n << endl;
        int pos = cur.n*2;
        if(!(pos<0||pos>=maxn||visited[pos])){
            q.push(node(pos,cur.depth+1));
            visited[pos] = true;
        }
        pos = cur.n+1;
        if(!(pos<0||pos>=maxn||visited[pos])){
            q.push(node(pos,cur.depth+1));
            visited[pos] = true;
        }
        pos = cur.n-1;
        if(!(pos<0||pos>=maxn||visited[pos])){
            q.push(node(pos,cur.depth+1));
            visited[pos] = true;
        }
    }
    return 0;
}