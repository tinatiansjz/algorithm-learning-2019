//棋牌覆盖问题
//NYOJ 45
//2018/11/11 10:39
//大数问题 用字符串来存 （此方法有问题）
#include <iostream>
#include <cstdio>
using namespace std;
long long cover(int k){
    if(k == 1){return 1L;}
    else{
        long n = cover(k-1);
        return 4*n + 1;
    }
}
int main(){
    freopen("P229_in.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    while(m--){
        int k;
        scanf("%d", &k);
        long long ans = cover(k);
        cout << ans << endl;
    }
    return 0;
}
