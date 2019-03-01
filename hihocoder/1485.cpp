#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
char a[maxn];
int c[maxn]; // count
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%s", a);
    int ans = maxn;
    int front = 0, rear = 0; // [rear, front)
    while(a[front] != '\0'){
        c[a[front]]++; front++;
        bool flag = false;
        while(c['h'] >= 2 && c['i'] >= 1 && c['o'] >= 1) {
            c[a[rear]]--; rear++; flag = true;
        }
        if(flag) {rear--; c[a[rear]]++;}
        if(c['h'] == 2 && c['i'] == 1 && c['o'] == 1){
            ans = min(ans, front-rear);
        }
    }
    if(ans == maxn) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}