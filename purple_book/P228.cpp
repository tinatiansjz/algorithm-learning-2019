//Binary Search
//2018/11/11 10:05
#include <iostream>
#include <cstdio>
using namespace std;
int bsearch(int* A, int x, int y, int v){
    int m;
    while(x < y){
        m = x+(y-x)/2;
        if(A[m] == v) return m;
        else if(A{m} > v) y = m;
        else x = m+1;
    }
    return -1;
}
int low_bound(int* A, int x, int y, int v){
    int m;
    while(x < y){
        m = x+(y-x)/2;
        if(A[m]>=v) y = m;
        else x = m+1;
    }
    return x;
}
int upper_bound(int* A, int x, int y, int v){
    int m;
    while(x < y){
        m = x+(y-x)/2;
        if(A[m]<=v) x = m+1;
        else y = m;
    }
    return x;
}
int main(){
    return 0;
}
