// 尺取法
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<char, int> m;
const int maxn = 1e5+5;
const int INF = 1e5+10;
char a[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%s", a);
    int j = 0, ans = INF;
    for(int i = 0; a[i]; i++){
        m[a[i]]++;
        bool flag = false;
        while(m['h'] >= 2 && m['i'] >= 1 && m['o'] >= 1){
            flag = true;
            m[a[j]]--; j++;
        }
        if(flag){
            j--; m[a[j]]++;
        }
        if(m['h'] == 2 && m['i'] == 1 && m['o'] == 1){
            // printf("front: %d, rear: %d\n", i, j);
            if(ans > i-j+1) ans = i-j+1;
        }
    }
    if(ans == INF) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}