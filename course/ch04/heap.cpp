// heap
// 2019/1/2 16:50
// max-heap
#include <iostream>
#include <cstdio>
using namespace std;
void debug(int* H, int n){
    for(int i = 1; i <= n; i++){
        cout << H[i] << " ";
    }
    cout << endl;
}
void sift_up(int* H, int n, int i){//i: index
    bool done = false;
    if(i == 1) return;
    while(i != 1 && !done){
        if(H[i] > H[i/2]){//exchange the values
            int tmp = H[i];
            H[i] = H[i/2]; H[i/2] = tmp;
            i /= 2;
        }else{
            done = true;
        }
    }
}
void sift_down(int* H, int n, int i){//i: index
    bool done = false;
    if(2*i > n) return;//leaf node
    while(2*i <= n && !done){
        i *= 2;
        if(i+1 < n && H[i+1] > H[i]) i = i+1;//i = right leaf
        if(H[i/2] < H[i]){
            int tmp = H[i];
            H[i] = H[i/2]; H[i/2] = tmp;
        }else{
            done = true;
        }
    }
}
void Insert(int* H, int& n, int x){//x: element
    n++;
    H[n] = x;
    sift_up(H, n, x);
}
void Delete(int* H, int& n, int i){//i: index
    int x = H[i], y = H[n];
    n--;
    if(i == n+1) return;
    H[i] = y;
    if(y >= x) sift_up(H, n, i);
    else sift_down(H, n, i);
}
void Makeheap(int* H, int n){
    for(int i = n/2; i >= 1; i--){
        sift_down(H, n, i);
        // debug(H, n);
    }
    
}
void Heapsort(int* H, int n){
    Makeheap(H, n);
    for(int j = n; j >= 2; j--){
        int tmp = H[1]; H[1] = H[j]; H[j] = tmp;//exchange A[j] and A[1]
        sift_down(H, j-1, 1);
        // debug(H, n);
    }
}
int main(){
    int H[10] = {0, 6, 34, 2, -1, 99, 8};
    Heapsort(H, 6);
    cout << "result: "; debug(H, 6);
    return 0;
}