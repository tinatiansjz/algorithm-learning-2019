//Finding the majority elements
//2018/11/14 10:07
//divide-and-conquer algorithm
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int count = 1;
//find the candidate
int candidate(int* A, int m, int n){
    int j = m+1, c = A[m];
    count = 1;
    while(j < n && count > 0){
        j++;
        if(A[j] == c) count++;
        else count--;
    }
    if(j == n) return c;
    else return candidate(A, j+1, n);
}
bool verify(int* A, int n, int& c){
    c = candidate(A, 0, n);
    int cand = A[c];
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == cand) sum++;
    }
    if(sum >= (n+1)/2){//取上界
        return true;
    }else{
        return false;
    }
}
int main(){
    int A[] = {1, 3, 2, 3, 3, 4, 3};
    int n = sizeof(A)/4;
    int c;
    if(verify(A, n, c)) cout << A[c] << endl;
    else cout << "Not found" << endl;
    return 0;
}
