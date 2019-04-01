// https://www.cnblogs.com/xiongtao/p/9282403.html
// https://ac.nowcoder.com/acm/contest/551/C
// 等概率随机生成 重复长度超过15的可能性忽略不计
#include<bits/stdc++.h>
#define inf 0x3f3f3f
typedef long long ll;
using namespace std;
set<string>s[100];
string a,t;
int main(){
    ll n,m;
    cin>>n>>m>>a;
    ll lap=0,ans=(n-m+1)*(n-m+2)/2;
    //cout<<ans<<endl;
    for(int i=m;i<=min(n,15LL);i++){
        for(int j=0;j+i-1<a.size();j++){
            t=a.substr(j,i);
            if(s[i].find(t)!=s[i].end())lap++;
            else s[i].insert(t);
        }
    }
    printf("%lld",ans-lap);
    return 0;
}