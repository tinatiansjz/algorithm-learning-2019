#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 150;
int a[maxn][2];
int main(){
    // freopen("in.txt", "r", stdin);
    int r, y, g; scanf("%d%d%d", &r, &y, &g);
    // cout << r << " " << y << " " << g << endl;
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        switch(a[i][0]){
            case 0: ans += a[i][1]; break;
            case 1: ans += a[i][1]; break;
            case 2: ans += a[i][1]+r; break;
            case 3: break;
        }
    }
    cout << ans << endl;
    return 0;
}