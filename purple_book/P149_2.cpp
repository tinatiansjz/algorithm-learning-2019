//2018/10/27    10:43
//UVa 679
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("P149_in.txt", "r", stdin);
    int D, I;
    while(scanf("%d%d", &D, &I) == 2){
        int k = 1;
        for(int i = 0; i < D-1; i++){
            if(I % 2) {k = k*2; I = (I+1)/2;}
            else{k = k*2 + 1; I /= 2;}
        }
        printf("%d\n", k);
    }
    return 0;
}
