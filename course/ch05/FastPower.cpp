//Fast power(整数）
//2018/11/8 16:10
#include <iostream>
#include <cstdio>
using namespace std;
int power(int a, int n){
    int ret = 1;
    while(n){
        ret = n&1 ? (ret*a) : ret;
        a *= a;
        n >>= 1;
    }
    return ret;
}
int main(){
    int ans = power(2, 3);
    cout << ans << endl;
    return 0;
}
