#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int a[maxn][2];
int r, y, g;
long long ans = 0;
int cal(int t){
    if(t>=0 && t<r) return r-t;
    if(t>=r && t<r+g) return 0;
    if(t>=r+g) return (r+g+y)-t+r;
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &r, &y, &g);
    // cout << r << " " << y << " " << g << endl;
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    for(int i = 0; i < n; i++){
        switch(a[i][0]){
            case 0:{
                ans += a[i][1];break;
            }
            case 1:{
                int tmp = (ans + 1LL*(r-a[i][1]))%(r+g+y);
                ans += 1LL*cal(tmp);break;
            }
            case 2:{
                int tmp = (ans + 1LL*(r+g+y-a[i][1]))%(r+g+y);
                ans += 1LL*cal(tmp);break;
            }
            case 3:{
                int tmp = (ans + 1LL*(r+g-a[i][1]))%(r+g+y);
                ans += 1LL*cal(tmp);break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}