// CodeForces - 1154G
#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e7+5;
int cnt[maxn];
pair<int, int> p;
int main(){
    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    ll ans = 1e18;
    int _max = -1;
    for(int i = 1; i <= n; i++){
        int tmp; scanf("%d", &tmp);
        if(tmp > _max) _max = tmp;
        if(cnt[tmp] && tmp < ans){
            p.first = cnt[tmp]; p.second = i;
            ans = tmp;
            continue;
        }
        cnt[tmp] = i;
    }
    for(int i = 1; i <= _max; i++){
        int one = -1;
        for(int j = i; j <= _max; j += i){
            if(!cnt[j]) continue;
            if(!(~one)){one = j; continue;}
            ll tmp = 1LL*one*j/__gcd(one, j);
            // cout << i << " " << one << " " << j << " " << tmp << endl;
            if(tmp < ans){
                ans = tmp; p.first = cnt[one]; p.second = cnt[j];
                // cout << "P: " << p.first << p.second << endl;
            }
            break;
        }
    }
    if(p.first < p.second)
        printf("%d %d\n", p.first, p.second);
    else
        printf("%d %d\n", p.second, p.first);
    return 0;
}