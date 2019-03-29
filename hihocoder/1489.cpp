// https://hihocoder.com/discuss/question/5720
// E(X+Y)=E(X)+E(Y)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double f[105];
int main(){
    // freopen("in.txt", "r", stdin);
    int P, Q, N; scanf("%d%d%d", &P, &Q, &N);
    f[100] = 1.0;
    for(int i = 99; i >= 0; i--){
        int j = min(i+Q, 100);
        f[i] = 1.0*i/100 + 1.0*(100-i)/100*(f[j]+1);
    }
    double ans = 0;
    for(int i = 1; i <= N; i++){
        ans += f[P];
        P >>= 1;
    }
    printf("%.2lf\n", ans);
    return 0;
}