#include <iostream>
#include <cstdio>
using namespace std;
bool InsertionSort(int* a, int n){
    for(int i = 1; i < n; i++){
        int x = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
    return true;
}
int main(){
    int a[] = {9, 8, 100, -1, 10, 7, 6, 0, 52, 9, 4, 90};
    if(InsertionSort(a, sizeof(a)/4)){
        for(int i = 0; i < sizeof(a)/4; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
