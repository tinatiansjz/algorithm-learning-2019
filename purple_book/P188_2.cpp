//Bit vector method (subset generation)
//2018/11/10 9:27
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
void print_subset(int* A, int n, int* B, int cur){
    if(cur == n){
        for(int i = 0; i < cur; i++){
            if(B[i]) printf("%d ", A[i]);
        }
        printf("\n");
        return;
    }
    B[cur] = 1;
    print_subset(A, n, B, cur+1);
    B[cur] = 0;
    print_subset(A, n, B, cur+1);
}
int main(){
    int a[] = {5, 4, 6};
    int* b = (int*)malloc(sizeof(a));
    print_subset(a, 3, b, 0);
    return 0;
}
