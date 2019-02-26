// 2019/2/3 11:41
// https://ac.nowcoder.com/acm/contest/332/D
// https://blog.csdn.net/w865629524/article/details/86751246?tdsourcetag=s_pctim_aiomsg
// Attention: consider from left to right
#include <iostream>
#include <cstdio>
#include <deque>
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        ans += a[i]/2; a[i] = a[i]%2;
        if(i < n-1 && a[i] == 1 && a[i+1] >= 1){
            ans++;
            a[i] = 0; a[i+1]--;
        }
    }
    cout << ans << endl;
    return 0;
}