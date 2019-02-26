// Turning Turtles (governing dynamics)
// http://hihocoder.com/problemset/problem/1172
// 2019/02/18
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e4+5;
char a[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    scanf("%s", a);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 'H') ans ^= (i+1);
    }
    if(!ans) cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}