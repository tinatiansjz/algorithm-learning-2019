// 线性乘法逆元
// 注意long long!!
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 3e6+5;
ll a[maxn];
int main(){
    int n, p; scanf("%d%d", &n, &p);
    a[1] = 1;
    for(int i = 2; i <= n; i++){
        a[i] = -(p/i)*a[p%i];
        a[i] = (a[i]%p+p)%p;
    }
    for(int i = 1; i <= n; i++)
        printf("%lld\n", a[i]);
    return 0;
}
