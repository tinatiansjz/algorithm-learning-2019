//purple book P185
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5;
int a[maxn];
void print_permutation(int n, int* A, int cur){
    if(cur == n){//递归边界
        for(int i = 0; i < n; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
    }else{
        for(int i = 1; i <= n; i++){//尝试在A[cur]中填各种整数
            int ok = 1;
            for(int j = 0; j < cur; j++){
                if(A[j] == i) ok = 0;
            }
            if(ok){
                A[cur] = i;
                print_permutation(n, A, cur+1);
            }
        }
    }
}
int main(){
    print_permutation(4, a, 0);
    return 0;
}
