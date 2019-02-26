// http://hihocoder.com/problemset/problem/1151
// 2019/02/17 16:23
// M[i][j] refers to the number of schemes from state i (kth column) to state j ((k+1)th column).
// the state of kth column
//   kth column    
//      ↓
// 0: 1 0     1: 1 0    2: 1 0    3: 1 0    4: 1 1    5: 1 1    6: 1 1    7: 1 1
//    1 0        1 0       1 1       1 1       1 0       1 0       1 1       1 1
//    1 0        1 1       1 0       1 1       1 0       1 1       1 0       1 1
// 1 represents the space occupied by tile; 0 empty
// Attention: we need to fill the (k+1)th column, rather than kth column
// M[8][8] = 
//     0 0 0 0 0 0 0 1
//     0 0 0 0 0 0 1 0
//     0 0 0 0 0 1 0 0
//     1 0 0 0 1 0 0 1
//     0 0 0 1 0 0 0 0
//     0 0 1 0 0 0 0 0
//     0 1 0 0 0 0 0 1
//     1 0 0 1 0 0 1 0
// initalize: A = [0,0,0,0,0,0,1]
// end with: state 7
#include <iostream>
#include <cstdio>
#define ll long long
#define N 8
using namespace std;
const int MOD = 12357;
struct mat{
    ll a[N][N];
    int l,r;
}A, B, C;
mat operator * (mat X, mat Y){
    mat Z;
    Z.l = X.l; Z.r = Y.r;
    for(int i = 0; i < X.l; i++)
        for(int j = 0; j < Y.r; j++){
            Z.a[i][j] = 0;
            for(int k = 0; k < X.r; k++)
                Z.a[i][j] = (Z.a[i][j] + X.a[i][k]*Y.a[k][j]%MOD)%MOD;
        }
    return Z;
}
void init(){
    A.a[0][7] = 1; A.l = 1; A.r = 8;
    // A.a[0][7] = 1; A.l = 1; A.r = 8;
    B.a[7][3] = B.a[7][6] = B.a[6][7] = B.a[3][7] = 1;
    for(int i = 0; i < 8; i++) B.a[i][7-i] = 1;
    B.l = B.r = 8;
    for(int i = 0; i < 8; i++) C.a[i][i] = 1;
    C.l = C.r = 8;
}
void cal(){
    init();
    int n; cin >> n;
    while(n){
        if(n&1) C = C*B;
        n >>= 1;
        B = B*B;
    }
    A = A*C;
    cout << A.a[0][7] << endl;
}
int main(){
    freopen("in.txt", "r", stdin);
    cal();
    return 0;
}