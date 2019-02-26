// https://ac.nowcoder.com/acm/contest/332/E
// 2019/2/3 11:48
// Prefix sum (二维前缀和）
// https://blog.csdn.net/w865629524/article/details/86751246?tdsourcetag=s_pctim_aiomsg
// sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j]
// a[i][j] = 1 (if h[i][j]>=d)
//         = 0 (if h[i][j]<d)
// (a,b)-(x,y) = 
//    sum[x][y]-sum[x][b-1]-sum[a-1][y]+sum[a-1][b-1]
// 将二维数组处理为一维数组
// (n+1)*(m+1)
// s[i][j] = s[i*(m+1)+j]
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e6;
int s[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    memset(s, 0, sizeof(s));
    int n, m, d; scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int t; scanf("%d", &t);
            t = t>=d?1:0;
            s[i*(m+1)+j] = s[(i-1)*(m+1)+j] + s[i*(m+1)+j-1] - s[(i-1)*(m+1)+j-1] + t;
        }
    }
    int T; scanf("%d", &T);
    while(T--){
        int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
        cout << s[x*(m+1)+y]-s[(a-1)*(m+1)+y]-s[x*(m+1)+b-1]+s[(a-1)*(m+1)+b-1] << endl;
    }
    return 0;
}
