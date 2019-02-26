#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100;
int n, m, k[maxn];
//保存两个数的和的序列
int kk[maxn*maxn];
bool binary_search(int x){
    //x的存在范围为kk[1], kk[2],..., kk[r-1]
    int l = 0, r = n*n;
    //反复操作直到存在范围为空
    while(r-l >= 1){
        int i = (r+l)/2;
        if(kk[i] == x)return true;
        else if(kk[i] < x) l = i+1;
        else r = i;
    }
    return false;
}
void solve(){
    //枚举k[c]+k[d]的和
    for(int c = 0; c < n; c++){
        for(int d = 0; d < n; d++){
            kk[c*n + d] = k[c] + k[d];
        }
    }
    sort(kk, kk+n*n);
    bool f = false;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(binary_search(m - k[a] - k[b])){
                f = true;
            }
        }
    }
    if(f) puts("Yes");
    else puts("No");
}
int main(){
    freopen("lots_in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> k[i];
    solve();
    return 0;
}
