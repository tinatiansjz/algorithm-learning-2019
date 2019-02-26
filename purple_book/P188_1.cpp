//Incremental subset construction
//2018/11/10 10:02
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
void print_subset(int* A, int n, int* pos, int cur){
    for(int i = 0; i < cur; i++){
        cout << A[pos[i]] << " ";
    }
    cout << endl;
    int s = cur ? pos[cur-1] + 1 : 0;
    for(int i = s; i < n; i++){
        pos[cur] = i;
        print_subset(A, n, pos, cur+1);
    }
}
int main(){
    int a[] = {5, 4, 6};
    int* pos = (int*)malloc(sizeof(a));
    print_subset(a, 3, pos, 0);
    return 0;
}
