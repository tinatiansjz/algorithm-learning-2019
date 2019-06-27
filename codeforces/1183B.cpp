#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
int a[maxn];
int n, k;
int rear, front; // [rear, front]
int main(){
    // freopen("in.txt", "r", stdin);
    cin.tie(0); ios_base::sync_with_stdio(false);
    int q; cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i == 0) {
                front = a[i]+k;
                rear = max(a[i]-k, 1);
            }else{
                rear = max(rear, max(1, a[i]-k));
                front = min(front, a[i]+k);
                if(front < rear) continue; // 是continue不是break啊啊啊
            }
        }
        if(front < rear) cout << "-1" << endl;
        else cout << front << endl;
    }
    return 0;
}