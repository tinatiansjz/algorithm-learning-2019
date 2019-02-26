// hihocoder 1438 区间求值
// 二分法 尺取法（滑动窗口）
// 求第k个区间的值，那么只要去寻找判断，小于当前数的区间个数有多少个，如果小于这个数的区间比k还大的话，说明当前的数肯定比要求的小，所以向右扩展，反之亦然
// 如果[l.r]是比k小，那么[l,r-1],[l,r-2]....[l,l]都是小于k的数，这里就用到了尺取法
// O(nlogn)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
int a[maxn], tmp[maxn];
ll n, m, vis[maxn];
ll check(ll mid){//尺取求比mid小的区间个数
    ll sum = 0, num = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 0, j = 0; i < n; i++){
        for(; j < n && sum+vis[a[j]] <= mid; j++){
            sum += vis[a[j]]; // sum记录[i, j]区间值（多少对元素值相同）
            vis[a[j]]++;// vis[k] 记录[i, j]区间内值为k的元素个数
        }
        // 尺取
        num += j-i; // [i, j), [i+1, j), ..., [j-1, j)
        vis[a[i]]--; // [i+1, j]
        sum -= vis[a[i]];// [i+1, j]
    }
    return num >= m;
}
int main(){
    freopen("in.txt", "r", stdin);
    ll ans;
    int t; scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            tmp[i] = a[i];
        }
        int cnt;
        // hash
        sort(tmp, tmp+n);
        cnt = unique(tmp, tmp+n) - tmp;
        for(int i = 0; i < n; i++) a[i] = lower_bound(tmp, tmp+cnt, a[i]) - tmp;
        ll left = 0, right = 1LL*n*(1LL*n-1)/2;
        while(left <= right){
            ll mid = left+(right-left)/2;
            if(check(mid)){//如果小于mid的区间个数比m多的话，说明值不够大
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}