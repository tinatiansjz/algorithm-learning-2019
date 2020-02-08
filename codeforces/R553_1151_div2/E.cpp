// https://codeforces.com/blog/entry/66602
// https://codeforces.com/contest/1151/problem/E
// Bravo!
// For each i from 0 to n set bi to 1 if l≤ai≤r, otherwise set it to 0.
// Now we can see that the value of f(l,r) is equal to the number of adjacent pairs (0,1) in array b.
// (a_{i-1}, a_i) -> (0,1)    sum_contribution:
// a_{i-1} < a_i
//    l: a_{i−1}+1->a_i     r: ai->n. The contribution is (a_i−a_{i−1})⋅(n−ai+1).
// a_{i-1} > a_i
//    l: 1->a_i             r: a_i->a_{i-1}-1. The contribution is ai⋅(a{i−1}−ai)
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
long long ans = 0;
int main(){
    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        if(a[i-1] < a[i]){
            ans += 1LL*(a[i]-a[i-1])*(n-a[i]+1);
        }else{
            ans += 1LL*a[i]*(a[i-1]-a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}