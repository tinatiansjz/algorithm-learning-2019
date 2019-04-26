// https://codeforces.com/contest/1080/problem/C
//https://codeforces.com/contest/1080/standings/page/1 (2 LinXuan)
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long LL;
using namespace std;
const int W = 0;
const int B = 1;

LL count(int x1, int y1, int x2, int y2, int color) {
    if (x1 > x2 || y1 > y2) return 0;
    LL ans = (LL)(x2 - x1 + 1) * (y2 - y1 + 1) / 2;
    if (!(((x2 ^ x1) | (y2 ^ y1) | (x1 ^ y1 ^ color)) & 1))
      ++ans;
    //printf("%d %d %d %d %c %I64d\n", x1, y1, x2, y2, "WB"[color], ans);
    return ans;
}

int main(){
    int q;
    scanf("%d", &q);
    while (q--) {
        int X, Y, x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d%d%d", &Y, &X, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        //count(1, 1, X, Y, W): 初始状态下白块的数量
        //count(x1, y1, x2, y2): because the white paint was spilled on it, 新增的白块数（黑->白）
        //count(x3, y3, x4, y4): because the black paint was spilled on it, 减少的白块数（白->黑）
        //count(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4), B): 重叠的部分，减去因为step1变白的黑块数
        LL w = count(1, 1, X, Y, W) + count(x1, y1, x2, y2, B) - count(x3, y3, x4, y4, W)
             - count(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4), B);
        printf("%I64d %I64d\n", w, (LL)X * Y - w);
    }
    return 0;
}
