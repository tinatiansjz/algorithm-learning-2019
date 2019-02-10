//merge sort
//2018/11/10 11:05
#include <iostream>
#include <cstdlib>
using namespace std;
void merge_sort(int* A, int x, int y, int* T){//[x, y)
    if(y-x > 1){
        int m = x + (y-x)/2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while(p < m || q < y){
            if(q >= y || (p<m && A[p]<=A[q])) T[i++] = A[p++];
            else T[i++] = A[q++];
        }
        for(i = x; i < y; i++) A[i] = T[i];
    }
}
int main(){
    int a[] = {2, 9, 1, 3, -1, 4, 7};
    int* tmp = (int*)malloc(sizeof(a));
    merge_sort(a, 0, sizeof(a)/4, tmp);
    for(int i = 0; i < sizeof(a)/4; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
