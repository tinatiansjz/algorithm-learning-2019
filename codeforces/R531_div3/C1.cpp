#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int main(){
    // freopen("in.txt", "r", stdin);
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y){cout << n << endl; return 0;}
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp <= x) cnt++;
    }
    // cnt = 0
    if(cnt == 0) {cout << "0" << endl; return 0;}
    cout << 1 + (cnt-1)/2 << endl;
    return 0;
}