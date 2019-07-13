//POJ-2431: Expedition
//2018/11/21 11:02
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct stop{
    int x; int v;
}s[10010];
bool cmp(stop s1, stop s2){
    return s1.x < s2.x;
}
int main(){
    int N, L, P;
    freopen("POJ2431_in.txt", "r", stdin);
    while(scanf("%d", &N) == 1){
        for(int i = 0; i < N; i++){
            scanf("%d%d", &s[i].x, &s[i].v);
        }
        scanf("%d%d", &L, &P);
        for(int i = 0; i < N; i++){
            s[i].x = L-s[i].x;
        }
        s[N].x = L;
        s[N++].v = 0;//把终点也认为是加油站
        sort(s, s+N, cmp);
        priority_queue<int, vector<int>, less<int> > Q;//值大的优先
        int rest = P;//剩余油量
        int ans = 0;//加油次数
        int pos = 0;//卡车所在的上一个位置
        for(int i = 0; i < N; i++){
            if(s[i].x < pos) continue;
            int dis = s[i].x - pos;//从上个加油站到此位置行驶的距离
            while(rest - dis < 0){
                if(Q.empty()){
                    ans = -1; break;
                }
                rest += Q.top(); Q.pop(); ans++;
            }
            if(ans == -1) break;
            rest = rest-dis; pos = s[i].x; Q.push(s[i].v);
        }
        cout << ans << endl;
    }
    return 0;
}
