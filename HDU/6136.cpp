//HDU-6136  Death Podracing
//2018/10/27    17:35
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int A = 2e5 + 10;
//保存人的信息
struct P{
    int d, v, id;
    bool operator < (const P& rhs) const{
        return d < rhs.d;
    }
}a[A];
//优先队列维护的信息
struct G{
    int p1, p2;
    double t;
    G(int p1=0, int p2=0, double t=0):p1(p1), p2(p2), t(t){}
    bool operator < (const G& rhs) const{
        return t > rhs.t;
    }
};
int L[A], R[A], all;
int n;//the number of the participants
int l;//the length of the circular
bool vis[A];
priority_queue<G> que;
//用于化简分数
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}
//得到两个选手相遇的时间
double Get_T(int x, int y){
    int dx = (a[y].d - a[x].d + l) % l;
    int dv = a[x].v - a[y].v;
    if(dv < 0){dv = -dv; dx = l - dx;}
    return 1.0*dx/dv;
}
//输出答案
void output(int x, int y){
    int dx = (a[y].d - a[x].d + l) % l;
    int dv = a[x].v - a[y].v;
    if(dv < 0){dv = -dv; dx = l - dx;}
    int tem = gcd(dx, dv);
    //printf("dx=%d, dv=%d\n", dx, dv);
    dx /= tem;
    dv /= tem;
    printf("%d/%d\n", dx, dv);
}
int main(){
    freopen("HDU-6136_in.txt", "r", stdin);
    int T;
    cin >> T;//the number of test cases
    while(T--){
        cin >> n >> l;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i].d);
            a[i].id = i;
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i].v);
        }
        sort(a, a+n);//sorted by location from small to large

        while(!que.empty()) que.pop();//clear the priority_queue
        for (int i = 0; i < n; i++){
            double time = Get_T(i, (i+1)%n);
            que.push(G(i, (i+1)%n, time));
            L[i] = (i-1+n)%n;//维护第i个选手左右的人是谁
            R[i] = (i+1)%n;
        }
        all = n;
        memset(vis, 0, sizeof(vis));
        while(que.size() > 1){
            G u = que.top();
            que.pop();
            int p1 = u.p1, p2 = u.p2;
            if(vis[p1] || vis[p2]) continue;//若p1, p2之前已经被淘汰
            if(L[p1] == p2 && R[p1] == p2) break;
            if(a[p1].id > a[p2].id){
                vis[p2] = 1;//标记被淘汰的点
                R[p1] = R[p2]; L[R[p2]] = p1;//更新左右情况
                double time = Get_T(p1, R[p2]);
                que.push(G(p1, R[p2], time));//插入新的时间
            }else{
                vis[p1] = 1;//标记被淘汰的点
                L[p2] = L[p1]; R[L[p1]] = p2;//更新左右情况
                double time = Get_T(L[p1], p2);
                que.push(G(L[p1], p2, time));//插入新的时间
            }
            if(--all <= 0) break;
        }
        G u = que.top();
        que.pop();
        int p1 = u.p1, p2 = u.p2;
        output(p1, p2);
    }
    return 0;
}
