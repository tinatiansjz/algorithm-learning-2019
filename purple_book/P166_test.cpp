//Abbott's Revenge, UVa 816
//2018/10/13    16:06
//Gain: while(cin >> a)中不能再套getline之类的不同流函数
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

void input(){
    char dir;
    cin >> r0 >> c0 >> dir >> r1 >> c1;
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
    int r0, c0, d0, r1, c1;
    while(cin >> name && name != "END"){
        memset(has_edge, false, sizeof(has_edge));
        memset(p, 0, sizeof(p));
        input();
        cout << name << endl;
    }
    return 0;
}
