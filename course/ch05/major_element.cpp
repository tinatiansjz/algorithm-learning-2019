//Finding the majority elements
//2018/11/14 10:07
//probabilistic algorithm
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int candidate(int* A, int n){
    double tmp = rand()*1.0/RAND_MAX;
    int c = tmp * n;
    //int c = rand() % n;
    return c;
}
bool verify(int* A, int c, int n){
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
    srand(time(NULL));
    int A[] = {1, 3, 2, 3, 3, 4, 3};
    int n = sizeof(A)/4;
    bool flag = false;
    int has;
    for(int i = 0; i < 20; i++){
        int c = candidate(A, n);
        cout << "candidate location: " << c << endl;
        if(verify(A, c, n)){flag = true; has = A[c]; break;}
    }
    if(flag) cout << has << endl;
    else cout << "Not found!" << endl;
    return 0;
}
