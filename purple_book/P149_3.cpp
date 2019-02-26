//UVa 679
//2018/10/27    16:02
#include <iostream>
#include <cstdio>
using namespace std;
int find(int I, int D, int k){
    if(D == 1) return k;
    else if(I%2 == 1) return find((I+1)/2, --D, 2*k);
    else return find(I/2, --D, 2*k+1);
}
int main(){
    freopen("P149_in.txt", "r", stdin);
    int D, I;
    while(scanf("%d%d", &D, &I) == 2){
        int k = 1;
        k = find(I, D, k);
        cout << k << endl;
    }
    return 0;
}
