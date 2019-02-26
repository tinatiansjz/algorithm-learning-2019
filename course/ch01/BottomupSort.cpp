#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100;
bool merge(int* a, int m, int p, int q, int r){
    if(p > q) return false;
    if(q > r) return false;
    if(p < 0) return false;
    if(r > m-1) return false;
    int b[maxn];
    int s = p, t = q+1, k = p;
    while(s <= q && t <= r){
        if(a[s] <= a[t]) {b[k++] = a[s]; s++;}
        else {b[k++] = a[t];t++;}
    }
    if(s == q+1){
        for (int i = t; i <= r; i++){
            b[k++] = a[i];
        }
    }
    if(t == r+1){
        for(int i = s; i <= q; i++){
            b[k++] = a[i];
        }
    }
    for(int i = p; i < r+1; i++){
        a[i] = b[i];
    }
    return true;
}
bool BottomupSort(int* a, int n){
    int t = 1;
    while(t < n){
        int s = t, i = 0;
        t = 2*s;
        while(i + t <= n-1){
            merge(a, n, i, i+s-1, i+t-1);
            i = i+t;
        }
        if(i+s < n-1) merge(a, n, i, i+s-1, n-1);
    }
    return true;
}
int main(){
    //int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 12, 13};
    int a[] = {9, 8, 100, -1, 10, 7, 6, 0, 52, 9, 4, 90};
    if(BottomupSort(a, sizeof(a)/4)){
        for(int i = 0; i < sizeof(a)/4; i++)
            cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
