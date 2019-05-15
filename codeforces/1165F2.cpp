// div3 F2
// ans属于[1, sum(ki)*2]，二分答案
// Attention: 多个卖相同kind商品只保留最后一个offer (天数) [Bravo! idea from kangba]
// 2019/5/15    11:30
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2e5+5;
struct sale{
    int day;
    int kind;
}b[maxn];
set<int> s;
vector<int> c[2*maxn];// c[i]表示第i天有哪些商品促销，注意开的数组大小为2*maxn
int tot = 0;
int n, m;
bool cmp(sale x, sale y){
    return x.day == y.day ? (x.kind < y.kind) : (x.day > y.day);
}
int k[maxn], tmp[maxn];
bool vis[maxn];
bool judge(int ans){
    memcpy(tmp+1, k+1, sizeof(int)*n);
    memset(vis, 0, sizeof(vis));
    int money = 0, cost = 0;
    for(int i = 0; i < tot; i++){
        if(b[i].day > ans) continue;
        if(vis[b[i].kind]) continue;
        c[b[i].day].push_back(b[i].kind);
        vis[b[i].kind] = true;
    }
    for(int i = 1; i <= ans; i++){
        money++;
        for(int j = 0; j < c[i].size() && money; j++)
            while(money && tmp[c[i][j]]){
                money--; cost++;
                tmp[c[i][j]]--;
            }
    }
    for(int i = 1; i <= n; i++)
        cost += tmp[i]*2;
    if(cost <= ans) return true;
    else return false;
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int sum = 0;
    s.clear();
    for(int i = 1; i <= n; i++){
        scanf("%d", &k[i]);
        if(k[i] == 0) s.insert(i);
        sum += k[i];
    }
    for(int i = 0; i < m; i++){
        int p, q; scanf("%d%d", &p, &q);
        if(s.count(q)) continue;
        b[tot].day = p; b[tot].kind = q;
        tot++;
    }
    sort(b, b+tot, cmp);
    int low = 1, high = sum*2;
    while(low < high){
        int mid = low+(high-low)/2;
        if(judge(mid))
            high = mid;
        else
            low = mid+1;
    }
    cout << low << endl;
    return 0;
}
