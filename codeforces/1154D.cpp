// CodeForces - 1154D
// greedy
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int n, b, A; scanf("%d%d%d", &n, &b, &A);
    int b1 = b, a1 = A, l = 0;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
        if(!a[i] && a1 > 0) {l++; a1--; continue;}
        if(!a[i] && b1 > 0) {l++; b1--; continue;}
        if(a[i] && a1 == A) {l++; a1--; continue;}
        if(a[i] && b1 > 0) {l++; b1--; a1++; continue;}
        if(a[i] && a1 > 0) {l++; a1--; continue;}
        if(!a1 && !b1) break;
    }
    cout << l << endl;
    return 0;
}