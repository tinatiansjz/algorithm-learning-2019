//HDU-1232
//并查集 kangba
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int fa[maxn];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
set<int> myset;
int main(){
    freopen("HDU-1232_in.txt", "r", stdin);
    int n, m;
    while (cin >> n && n){
        cin >> m;
        for(int i = 0; i <= n; i++) fa[i] = i;
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            fa[find(u)] = find(v);
        }
        myset.clear();
        for(int i = 1; i <= n; i++){
            myset.insert(find(i));
        }
        cout << myset.size() - 1 << endl;
    }
    return 0;
}
