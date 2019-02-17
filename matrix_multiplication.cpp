// Fibonacci, matrix fast power
// 2019/2/14 17:01
#include <iostream>
#include <cstdio>
#define type long long
using namespace std;
typedef long long ll;
const int N = 3;
const long long MOD = 9999997;
struct mat{
    type a[N][N];
    int l, r;
}A, B, C;
mat operator * (mat X, mat Y){
    mat Z;
    Z.l = X.l;
    Z.r = Y.r;
    for(int i = 0; i < X.l; i++)
        for(int j = 0; j < Y.r; j++){
            Z.a[i][j] = 0;
            for(int k = 0; k < X.r; k++)
                Z.a[i][j] = (Z.a[i][j]+X.a[i][k]*Y.a[k][j]%MOD)%MOD;
        }
    return Z;
}
int main(){
    A.l = 1; A.r = 2; A.a[0][0] = 1; A.a[0][1] = 1;
    B.l = B.r = 2;
    B.a[0][0] = 0; B.a[0][1] = B.a[1][0] = B.a[1][1] = 1;
    C.l = C.r = 2;
    for(int i = 0; i < 2; i++) C.a[i][i] = 1;
    int n; cin >> n; n--;
    while(n){
        if(n&1) C = C*B;
        n = n>>1;
        B = B*B;
    }
    A = A*C;
    cout << A.a[0][0] << endl;
    return 0;
}
