//https://blog.csdn.net/nameofcsdn/article/details/69055482
//2018/5/4  17:09
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n, m, list[1010], loc[1010], p, q;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        list[i] = i;
        loc[i] = i;
    }
    while(m--){
        cin >> p >> q;
        int d = q > 0 ? 1:-1;
        for(int i = loc[p]; i != loc[p] + q; i += d){
            list[i] = list[i+d];
            loc[list[i]] = i;
        }
        list[loc[p]+q] = p;
        loc[p] += q;
    }
    for(int i = 1; i < n; i++) cout << list[i] << " ";
    cout << list[n] << endl;
    return 0;
}
