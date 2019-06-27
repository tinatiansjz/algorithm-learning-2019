// Build the prefix-xor of the array, not the array itself, then build the array from it. Let the prefix-xor array be called b.
// https://codeforces.com/blog/entry/67388
// b[i] = a[1]^a[2]^...^a[i]
// a[l]^a[l+1]^...^a[r] = b[l-1]^b[r]
// a[i] = b[i]^b[i-1]
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 3e5+5;
int a[maxn];
int b[maxn], tot = 0;
bool vis[maxn];
int main(){
    freopen("in.txt", "r", stdin);
    int n, x; cin >> n >> x;
    // 特判
    if(n == 1 && x != 1){cout << "1\n1\n"; return 0;}
    if(n == 1 && x == 1){cout << "0" << endl; return 0;}
    int num = (int)pow(2, n); // threshold
    if(x >= num){
        cout << num-1 << endl;
        for(int i = 1; i < num; i++)
            cout << ((i-1)^i) << " ";
        cout << endl;
    }else{
        memset(vis, 0, sizeof(vis));
        vis[x] = true;
        for(int i = 1; i < num; i++){
            if(!vis[i]){
                b[++tot] = i;
                vis[i] = true;
                if((x^i) < num && !vis[x^i]) vis[x^i] = true;
            }
        }
        cout << tot << endl;
        for(int i = 1; i <= tot; i++)
            cout << (b[i-1]^b[i]) << " ";
        cout << endl;
    }
    return 0;
}