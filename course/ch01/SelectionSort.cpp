#include <iostream>
#include <cstdio>
using namespace std;
bool SelectionSort(int* a, int n){
    for (int i = 0; i < n-1; i++){
        int k = i;
        for(j = i+1; j < n; j++){
            if(a[j] < a[k]) k = j;
        }
        if(k != i) {int tmp = a[i]; a[i] = a[k]; a[k] = tmp;}
    }
    return true;
}
int main(){
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    if(SelectionSort(a, 9)){
        for(int i = 0; i < 9; i++)
            cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
