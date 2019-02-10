//calculate the result of modulo 1e9+7 of item 1e18 of the Fibonacci sequence
//by kangba
//2018/11/8 16:57
//Matrix Fast Power
#include <iostream>
using namespace std;
const long long MOD = 1e9+7;
void Matrix(long long a[2][2], long long b[2][2]){
	long long tmp[2][2] = {0};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j]%MOD)%MOD;
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
    int maxn = 1000;
    long long n = 1e18;
    long long trans[2][2] = {1, 1, 1, 0};
    long long ans[2][2] = {1, 0, 0, 1};//initial
    while(n){
        if(n & 1) Matrix(ans, trans);
        Matrix(trans, trans);
        n >>= 1;
    }
    cout << ans[0][1] << endl;
    return 0;
}
