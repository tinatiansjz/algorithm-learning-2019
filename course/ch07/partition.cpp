//整数拆分问题
//recursion
//2018/11/28    10:47
/* f(n, m) = 1                          n=1, m=1
 *         = f(n, n)                    n<m
 *         = 1+f(n, n-1)                n=m
 *         = f(n, m-1)+f(n-m, m)        n>m>1
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100;
long long partition(int n, int m){
    if(n == 1 || m == 1){return 1;}
    if(n < m){return partition(n, n);}
    if(n == m){return 1 + partition(n, n-1);}
    else{
        return partition(n-m, m) + partition(n, m-1);
    }
}
