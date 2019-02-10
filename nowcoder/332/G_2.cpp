// https://blog.csdn.net/charles_zaqdt/article/details/86754296
// Find the law !!!
// 当一个数按位或一个比它大的数的时候它才会变
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
int main(){
    freopen("in.txt", "r", stdin);
    ll a, b;
    while(cin >> a >> b){
        if(a == b){
            cout << a << endl;
            continue;
        }
        ll ans = a|(a+1);
        ll tot = 0;
        while(ans < b){
            tot++;
            ans |= (ans+1);
        }
        cout << "tot: " << tot << endl;
        cout << ans << endl;
    }
    return 0;
}
