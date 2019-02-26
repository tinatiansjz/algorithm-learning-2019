// https://codeforces.com/contest/1095/problem/E
// E. Almost Regular Bracket Sequence
// 2018/12/27
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
int a[maxn], b[maxn], c[maxn];
int main(){
    freopen("in.txt", "r", stdin);
    int n, k = 0;
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + ((s[i] == '(')? 1 : -1);
    }
    b[0] = a[0];
    for(int i = 1; i <= n; i++){
        b[i] = min(b[i-1], a[i]);
    }
    c[n] = a[n];
    for(int i = n-1; i >= 0; i--){
        c[i] = min(c[i+1], a[i]);
    }
    if(a[n] == 2){
        for(int i = 1; i <= n; i++){
            if(a[i]-a[i-1] == 1 && b[i-1] >= 0 && c[i] >= 2){
                k++;
            }
        }
    }else if(a[n] == -2){
        for(int i = 1; i <= n; i++){
            if(a[i]-a[i-1] == -1 && b[i-1] >= 0 && c[i] >= -2){
                k++;
            }
        }
    }
    printf("%d\n", k);
    return 0;
}
