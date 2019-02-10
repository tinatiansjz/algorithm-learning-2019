//POJ-3070 Fibonacci
//Matrix Fast Power
//2018/11/8 16:34
#include <iostream>
#include <cstdio>
using namespace std;
const int MOD = 10000;
int n;
void Matrix(int a[2][2], int b[2][2]){
    int tmp[2][2] = {0};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j])%MOD;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = tmp[i][j];
        }
    }
}
int main(){
    freopen("POJ-3070_in.txt", "r", stdin);
    while(cin >> n && n != -1){
        int trans[2][2] = {1, 1, 1, 0};
        int ans[2][2] = {1, 0, 0, 1};//initialize: identity matrix
        while(n){
            if(n & 1) Matrix(ans, trans);
            Matrix(trans, trans);
            n >>= 1;
        }
        cout << ans[0][1] << endl;
    }
    return 0;
}
