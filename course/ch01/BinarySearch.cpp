#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int BinarySearch(int* a, int n, int x){
    //x exists among x[low], a[low+1],..., a[high-1]
    int low = 0, high = n-1, j = -1;
    while(low <= high && (j == -1)){
        int mid = (low+high)/2;
        if(x == a[mid]) j = mid;
        else if(x < a[mid]) high = mid;
        else low = mid+1;
    }
    return j;
}
int main(){
    int a[] = {3, 1, 18, 199, 5, 5, 10, 29, -1, 88};
    sort(a, a+sizeof(a)/4);
    int j = BinarySearch(a, 10, 29);
    cout << j << endl;
    return 0;
}
