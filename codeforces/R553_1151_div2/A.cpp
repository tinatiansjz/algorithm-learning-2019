#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50+5;
const int INF = 0x3f3f3f3f;
char a[maxn];
const char g[] = {'A', 'C', 'T', 'G'};
inline int cal(char a, int b){
    int m = max(a - b, b-a);
    int n = 26-m;
    return min(m, n);
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    scanf("%s", a);
    int ans = INF;
    for(int i = 0; i <= n-4; i++){
        int tmp = cal(a[i], 'A')+cal(a[i+1], 'C')+cal(a[i+2], 'T')+cal(a[i+3], 'G');
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}