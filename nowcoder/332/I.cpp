// https://blog.csdn.net/w865629524/article/details/86751246?tdsourcetag=s_pctim_aiomsg
// 2019/2/8 22:16
// https://ac.nowcoder.com/acm/contest/332/I
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6+5;
char s[maxn], t[maxn];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(idx > 0 && s[i] == t[idx]) {
            ans += 10;
            idx--;
            continue;
        }
        t[++idx] = s[i];// t[1] = s[0]
    }
    ans += idx/2*5;
    cout << ans << endl;
    return 0;
}
