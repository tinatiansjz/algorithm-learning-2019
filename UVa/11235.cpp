// memset(d, 0, sizeof(d)) 会TLE...
// 2019.6.24    19:18
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
// RLE: run length encoding 游程编码
int tot; // the number of segments
int seg[maxn][2]; // the start and the end of each segment
int val[maxn]; // val[i]: 第i段的数值(没用)
int cnt[maxn]; // cnt[i]: 第i段的长度
int num[maxn]; // num[p]: 位置p所在段的编号
int left[maxn], right[maxn]; // left[p], right[p]: 位置p所在段的左右端点位置
int n, q;
int d[maxn][21];
void RMQ_init(){// cnt[1], cnt[2],...,cnt[tot]
    // memset(d, 0, sizeof(d));
    for(int i = 1; i <= tot; i++) d[i][0] = cnt[i];
    for(int j = 1; (1<<j) <= tot; j++)
        for(int i = 1; i+(1<<j)-1 <= tot; i++)
            d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
}
int RMQ_query(int L, int R){
    if(L > R) return 0;
    int k = 0;
    while(1<<(k+1) < R-L+1) k++;
    return max(d[L][k], d[R-(1<<k)+1][k]);
}
int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) && n){
        tot = 0; // init
        scanf("%d", &q);
        int start = -1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(i == 1 || i == n || a[i] > a[i-1]){ // 新段开始
                if(i > 1){
                    cnt[++tot] = i-start;
                    for(int j = start; j <= i; j++){
                        num[j] = tot; left[j] = start; right[j] = i-1;
                    }
                }
                start = i;
            }
        }
        RMQ_init();
        for(int i = 0, L, R; i < q; i++){
            scanf("%d%d", &L, &R);
            if(a[L] == a[R]){
                printf("%d\n", R-L+1);
                continue;
            }
            int cnt1 = right[L]-L+1;
            int cnt2 = R-left[R]+1;
            int cnt3 = RMQ_query(num[L]+1, num[R]-1);
            int tmp = max(cnt1, cnt2);
            tmp = max(tmp, cnt3);
            printf("%d\n", tmp);
        }
    }
    return 0;
}