// https://blog.csdn.net/w865629524/article/details/86751246?tdsourcetag=s_pctim_aiomsg
// 2019/2/3 21:52
// https://ac.nowcoder.com/acm/contest/332/G
// 研究每个比特位是否在a到b的区间中出现过
// 只要区间长度大于等于2^(i+1),那么第i个比特位就一定会在a到b的区间中出现。且如果区间长度不够大，而且在a和b中这个比特位都没有出现过的话，那么这个比特位在从a到b的区间中也不会出现
//  所以只要枚举每个比特位，判断a+2^i <=b是否成立，就可以判断第i个比特位是否为1
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
int main(){
    freopen("in.txt", "r", stdin);
    ll a, b;
    while(scanf("%lld%lld", &a, &b) == 2){
        ll ans = a|b;
        ll t = 1;
        ll tot = 0;
        while(t <= b){
            tot++;
            if(a+t <= b) ans |= t;
            t <<= 1;
        }
        cout << "tot: " << tot << endl;
        printf("%lld\n", ans);
    }
    return 0;
}
