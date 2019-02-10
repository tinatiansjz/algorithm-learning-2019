#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50;
int main(){
    freopen("lots_in.txt", "r", stdin);
    int n, m, k[maxn];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    bool f = false;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            for(int c = 0; c < n; c++){
                for(int d = 0; d < n; d++){
                    if(k[a] + k[b] + k[c] + k[d] == m){
                        f = true;
                        break;
                    }
                }
                if(f) break;
            }
            if(f) break;
        }
        if(f) break;
    }
    if(f) puts("Yes");
    else puts("No");
    return 0;
}
