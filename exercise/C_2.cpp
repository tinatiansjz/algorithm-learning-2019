//C - {A} + {B} 
//using array
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m;
int a[20010];
int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2){
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);//把第一个数组的元素存入数组
        }
        for (int i = n; i < n+m; i++){
            scanf("%d", &a[i]);//把第二个数组的元素存入数组
        }
        sort(a, a+n+m);//使用sort快排进行排序
        printf("%d", a[0]);
        for(int i = 1; i < n+m; i++){
            if(a[i] != a[i-1])
                printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
