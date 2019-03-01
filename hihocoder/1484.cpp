// g++ -std=c++11
// 非常复杂+繁琐的搜索+DP题目
// http://hihocoder.com/problemset/problem/1484
// 2019/2/25
// http://hihocoder.com/contest/hiho242/solution/1454955
// 没看太懂，有时间再仔细研究下，觉得蛮有意思的
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cstring>
#define long long ll
using namespace std;
int N, M, K;
struct Point{
    int x = 0, y = 0;
    int GetIdx(){
        return x*4+y;
    }
    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }
};
struct Pattern {
    int weight = 0;
    vector<Point> pts;
    bitset<200> mask;
}patterns[20], final;

int f[18][1 << 18];
inline int CalcLineIdx(int a, int b){
    return a*(31-a)/2 + (b-a-1); // hash ?
}
inline void SetMaskBit(Point& x, Point& y, Pattern& pat){
    int a = x.GetIdx(), b = y.GetIdx();
    if(a == b) return;
    if(b < a) swap(a, b);
    if(a/4 == b/4){// x1 == x2
        for(int i = a+1; i <= b; i++)
            pat.mask.set(CalcLineIdx(i-1, i));
    }else if((b-a)%4 == 0){// y1 == y2
        for(int i = a+4; i <= b; i+=4)
            pat.mask.set(CalcLineIdx(i-4, i));
    }else if((b-a)%3 == 0 && (b-a)/3 == b/4-a/4){// x2+y2 == x1+y1
        for(int i = a+3; i <= b; i+=3)
            pat.mask.set(CalcLineIdx(i-3, i));
    }else if((b-a)%5 == 0 && (b-a)/5 == b/4-a/4){// y2-x2 == y1-x1
        for(int i = a+5; i <= b; i+=5)
            pat.mask.set(CalcLineIdx(i-5, i));
    }else{
        pat.mask.set(CalcLineIdx(a, b));
    }
}
void CalcMask(Pattern& pat){
    for(int i = 1; i < pat.pts.size(); i++){
        SetMaskBit(pat.pts[i-1], pat.pts[i], pat);
    }
}
// 令f[i][state]为当前处于第i幅模式图且合法连接模式图集合为state是否可行，通过枚举下一幅图j进行转移。
int dp(int selected, int cur){ // ?
    if(f[cur][selected] != -1)
        return f[cur][selected];
    int ret = -1, ones = 0;
    for(int i = 0; i < N; i++){
        if((1<<i) & selected){ // select[i] == 1
            ones += 1;
            if(i != cur && patterns[i].pts.back() == patterns[cur].pts[0]){
                ret = dp(selected^(1<<cur), i);
                if(ret == 1) break;
            }
        }
    }
    if(ones == 1) f[cur][selected] = 1;
    else f[cur][selected] = max(0, ret);
    return f[cur][selected];
}
int Check(int selected){
    int ret = -1;
    for(int i = 0; i < 20; i++){
        if((i<<i) & selected){
            ret = dp(selected, i); // ret = f[i][selected]
            if(ret == 1) break;
        }
    }
    if(ret != 1) return 1 << 30;
    else{
        int weight = 0;
        for(int i = 0; i < 20; i++)
            if((1<<i) & selected)
                weight += patterns[i].weight;
        return weight;
    }
}
void dfs(int idx, bitset<200> cur_mask, int selected, int& ans){
    if(cur_mask == final.mask)
        ans = min(ans, Check(selected));
    if(idx == N) return;
    // 选第idx个pattern
    dfs(idx+1, cur_mask | patterns[idx].mask, selected | (1<<idx), ans);
    // 不选第idx个pattern
    dfs(idx+1, cur_mask, selected, ans);
}
int Solution(){
    for(int i = 0; i < N; i++)
        CalcMask(patterns[i]);
    for(int i = 0; i < M; i++)
        SetMaskBit(final.pts[i*2], final.pts[i*2+1], final);
    int ans = 1 << 30;
    memset(f, -1, sizeof(f));
    dfs(0, bitset<200>(), 0, ans);
    return ans;
}
int main(){
    freopen("in.txt", "r", stdin);
    int t;
    Point p;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &t, &patterns[i].weight);
        for(int j = 0; j < t; j++){
            scanf("%d%d", &p.x, &p.y);
            p.x -= 1; p.y -= 1;
            patterns[i].pts.emplace_back(p);
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &p.x, &p.y);
        p.x -= 1; p.y -= 1;
        final.pts.emplace_back(p);
        scanf("%d%d", &p.x, &p.y);
        p.x -= 1; p.y -= 1;
        final.pts.emplace_back(p);
    }
    cout << Solution() << endl;
    return 0;
}
