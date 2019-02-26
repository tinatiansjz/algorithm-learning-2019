//Abbott's Revenge, UVa 816
//2018/10/13    16:06
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
using namespace std;

struct Node{
    int r;
    int c;
    int dir;
    Node(int r=0, int c=0, int dir=0):r(r), c(c), dir(dir) {}
};
//int  d[r][c][dir]              初始状态到(r,c,dir)的最短长度
//Node p[r][c][dir]              保存了状态(r,c,dir)在BFS树中的父节点
//int  has_edge[r][c][dir][turn] 表示当前状态是(r,c,dir),是否可以沿着转弯方向turn行进
bool has_edge[10][10][4][3];
int  d[10][10][4];
Node p[10][10][4];
int r0, c0, d0; //initial state
int r2, c2;//final state
int r1, c1;//next state after the initial state
const char* dirs = "NESW";//顺时针旋转
const char* turns = "FLR";

//行走函数，根据当前状态和转弯方式，计算出后继状态
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int dir_id(char c){
    return strchr(dirs, c) - dirs;
}
int turn_id(char c){
    return strchr(turns, c) - turns;
}

Node walk(const Node& u, int turn){
    int dir = u.dir;
    if(turn == 1) dir = (dir + 3) % 4;//left
    if(turn == 2) dir = (dir + 1) % 4;//right
    return Node(u.r + dr[dir], u.c + dc[dir], dir);
}
//打印最短路径，用vector保存路径
void print_ans(Node u){
    //从目标节点逆序追溯到初始节点
    vector<Node> nodes;
    for(;;){
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir] == 0) break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0, c0, d0));

    //打印解，每行10个
    int cnt = 0;
    for (int i = nodes.size() - 1; i >= 0; i--){
        if(cnt % 10 == 0) printf(" ");
        printf(" (%d,%d)", nodes[i].r, nodes[i].c);
        if(++cnt % 10 == 0) printf("\n");
    }
    if(nodes.size() % 10 != 0) printf("\n");
}
bool inside(int x, int y){
    return (x >= 1 && x <= 9 && y >= 1 && y <= 9);
}
//BFS主过程
void solve(){
    queue<Node> q;
    memset(d, -1, sizeof(d));
    Node u(r1, c1, d0);
    d[u.r][u.c][u.dir] = 0;//访问u节点
    q.push(u);
    while(!q.empty()){
        Node u = q.front(); q.pop();
        if(u.r == r2 && u.c == c2){//搜索到final节点
            print_ans(u);
            return;
        }
        for(int i = 0; i < 3; i++){
            Node v = walk(u, i);
            if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) \
                    && d[v.r][v.c][v.dir] < 0){
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf("No Solution Possible\n");
}
void input(){
    char dir;
    cin >> r0 >> c0 >> dir >> r2 >> c2;
    d0 = dir_id(dir);
    r1 = r0 + dr[d0];
    c1 = c0 + dc[d0];
    int x, y;
    string str;
    while(cin >> x && x){
        cin >> y;
        while(cin >> str && str[0] != '*'){
            for (int i = 1; i < str.size(); i++){
                has_edge[x][y][dir_id(str[0])][turn_id(str[i])] = true;
            }
        }
    }
    //string s, buf;
    //while(getline(cin, s) && s != "0"){
    //    s[s.length()-1] = ' ';
    //    stringstream ss(s);
    //    printf("**\n"); fflush(stdout);
    //    int r, c;
    //    ss >> r >> c;
    //    while(ss >> buf && buf[0] != '*'){
    //        int d = dir_id(buf[0]);
    //        for (int i = 1; i < buf.length(); i++){
    //            int turn = turn_id(buf[i]);
    //            has_edge[r][c][d][turn] = true;
    //        }
    //    }
    //}
}

int main(){
    freopen("P166_in.txt", "r", stdin);
    string name;
    while(cin >> name && name != "END"){
        memset(has_edge, false, sizeof(has_edge));
        memset(p, 0, sizeof(p));
        input();
//        printf("r0=%d, c0=%d, d0=%d, r1=%d, c1=%d, r2=%d, c2=%d\n", r0, c0, d0, r1, c1, r2, c2);
        cout << name << endl;
        solve();
    }
    return 0;
}
