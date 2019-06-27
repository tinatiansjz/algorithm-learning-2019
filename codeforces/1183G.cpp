#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
int f[maxn];
struct node{
    int type;
    int like;
    int cnt;
}b[maxn];
set<int> s;
int n, tot;
void init(){
    s.clear();
    tot = 0;
}
bool cmp1(node x, node y){
    return x.cnt == y.cnt ? (x.like > y.like) : (x.cnt > y.cnt);
}
bool cmp2(node x, node y){
    return x.like == y.like ? (x.cnt > y.cnt) : (x.like > y.like);
}
vector<int> kindex;
int main(){
    // freopen("in.txt", "r", stdin);
    int q; scanf("%d", &q);
    memset(f,0,sizeof(f));
    while(q--){
        scanf("%d", &n);
        init(); 
        kindex.clear();
        for(int i = 0, tmp; i < n; i++){
            scanf("%d%d", &a[i], &tmp);
            f[a[i]] += tmp;
            kindex.push_back(a[i]);
        }
        sort(a, a+n);
        for(int i = 0; i < n; i++)
            if(i == 0 || a[i] > a[i-1]){
                b[tot].cnt = 1;
                b[tot].like = f[a[i]];
                b[tot++].type = a[i];
            }else{
                b[tot-1].cnt++;
            }
        sort(b, b+tot, cmp1);
        int ans1 = 0, ans2 = 0, cur;
        for(int i = 0; i < tot; i++){
            if(i == 0){
                ans1 += b[0].cnt;
                cur = b[0].cnt;
            }else{
                if(b[i].cnt >= cur && cur >= 1){
                    ans1 += (cur-1);
                    cur--;
                }else{
                    ans1 += b[i].cnt;
                    cur = b[i].cnt;
                }
            }
            if(cur == 0) break;
            s.insert(-cur);
        }
        // cout << ans1 << " ";
        sort(b, b+tot, cmp2);
        for(int i = 0; i < tot && !s.empty(); i++){
            set<int>::iterator it = s.lower_bound(-b[i].cnt);
            if(it == s.end()) continue;
            ans2 += min(b[i].like, -(*it));
            s.erase(it);
        }
        cout << ans1 << " " << ans2 << endl;
        int ins = kindex.size();
        for(int i = 0; i < ins; i++){
            f[kindex[i]] = 0;
        }
    }
    return 0;
}