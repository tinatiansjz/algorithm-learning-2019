// 1183F
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5+5;
bool vis[maxn];
int n, _max, ans;
void cal(int x){// 删除x的因子
    for(int i = 2; i*i <= x; i++)
        if(x%i == 0){
            vis[x/i] = false;
            vis[i] = false;
        }
}
int main(){
    // freopen("in.txt", "r", stdin);
    int q; scanf("%d", &q);
    while(q--){
        memset(vis, 0, sizeof(vis));
        _max = 0;
        ans = -1;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int tmp; scanf("%d", &tmp);
            vis[tmp] = true;
            _max = max(_max, tmp);
        }
        if(_max%2 == 0 && _max%3 == 0 && _max%5 == 0){
            if(vis[_max/2] && vis[_max/3] && vis[_max/5])
                ans = _max/2 + _max/3 + _max/5;
        }
        int ans2 = _max;
        cal(_max);
        for(int i = _max-1; i >= 2; i--){
            if(vis[i]) {
                ans2 += i;
                _max = i;
                break;
            }
        }
        cal(_max);
        for(int i = _max-1; i >= 2; i--){
            if(vis[i]){
                ans2 += i;
                break;
            }
        }
        // cout << ans << " " << ans2 << endl;
        cout << max(ans, ans2) << endl;
    }
}