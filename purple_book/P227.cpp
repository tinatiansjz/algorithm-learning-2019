//Quick Sort
//2018/11/11 09:36
#include <iostream>
#include <cstdio>
using namespace std;
void QuickSort(int* a, int s, int t){
    int i = s, j = t-1;
    int tmp;
    if(s < t-1){
        tmp = a[s];
        while(i != j){
            while(j>i && a[j] >= tmp) j--;
            a[i] = a[j];
            while(i<j && a[i] <= tmp) i++;
            a[j] = a[i];
        }
        a[i] = tmp;
        QuickSort(a, s, i);
        QuickSort(a, i+1, t);
    }
}
int main(){
    int a[] = {0, -9, 1, 3, 2, 5, 4, 2, 8, 3, 92, 5};
    QuickSort(a, 0, sizeof(a)/4);
    for(int i = 0; i < sizeof(a)/4; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
