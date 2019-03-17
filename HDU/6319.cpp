// HDU 6319
// 2019/2/5 10:16
// TODO
// Reversely construct a monotonic queue, starting from i+m-1<=n.
// If the forward is the last one, the reverse is the first one.
// GET:
// 1. initalize in every case (maxans, countans)
// 2. monotonic queue saves the indexes of the elements
// 3. an array with front and rear to implement the montonic queue
//    (deque possesses a high complexity -> TLE)
// 4. rely on yourself
// Confusion:
// Add the dichotomy part (int bound()) -> TLE ???
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e7+5;
int n,m,k,q,p,r,MOD;
int a[maxn];
// monotonic queue [front, rear) 
// save the index of the element
int qu[maxn];
long long maxans, countans;
inline int bound(int x, int y, int v){
    // find the first position with the value not greater than v
    while(x < y){
        int m = x+(y-x)/2;
        if(a[qu[m]] <= v) y = m;
        else x = m+1; 
    }
    return x;
}
void solve(){
    maxans = 0; countans = 0;
    int front = 0, rear = 0;
    for(int i = n; i >= 1; i--){
        // while(rear > front && a[i] >= a[qu[rear-1]]) rear--;
        rear = bound(front, rear, a[i]);
        qu[rear++] = i;
        if(i > n-m+1) continue;
        while(qu[front] > i+m-1) front++;
        countans += (rear-front)^i;
        maxans += a[qu[front]]^i;
    }
}
int main(){
    freopen("in.txt", "r", stdin);
    int T; cin >> T;
    while(T--){
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &MOD);
        for(int i = 1; i <= k; i++) scanf("%d", &a[i]);
        for(int i = k+1; i <= n; i++) a[i] = ((long long)p*a[i-1]%MOD + (long long)q*i%MOD + r%MOD)%MOD;
        solve();
        printf("%lld %lld\n", maxans, countans);
    }
    return 0;
}