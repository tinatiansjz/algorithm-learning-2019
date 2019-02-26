// To be solved
// To be understood
// https://codeforces.com/contest/1106/problem/E
// 2019/2/1 09:04
// by Vit.C
#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
long long f[maxn][202];
struct state{
    int c;
    int w, d;//w:value, d:duration
};
vector<state> v[maxn];
int n, m, k;
bool operator < (state a, state b){
    if(a.w == b.w) return a.d > b.d;
    return a.w > b.w;
}
multiset<state> ms;
int w[maxn], d[maxn];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    int cl = 0;
    for(int i = 0,l,r,d,w; i < k; i++){
        scanf("%d%d%d%d", &l, &r, &d, &w); cl = max(cl, d+1);
        v[l].push_back((state){1, w, d});
        v[r+1].push_back((state){-1, w, d});
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j].c == 1) ms.insert((state){1, v[i][j].w, v[i][j].d});
            else ms.erase(ms.find((state){1, v[i][j].w, v[i][j].d}));
        }
        multiset<state>::iteratoe it = ms.begin();
        if(it != ms.end()) w[i] = it->w, d[i] = it->d;
        else w[i] = 0, d[i] = i;
    }
	for(int i = 2;i <= n+1;i++){
        for(int j = 0;j <= i && j <= m;j++) f[i][j] = 1e18;
    }
    long long ans = 0;
    for(int i = 1 ; i <= cl;i++){
        for(int j = 0;j <= i && j <= m;j++){
            if(f[i][j] == 1e18) continue;
            if(j) f[i][j] = min(f[i][j] , f[i][j - 1]);
            f[d[i] + 1][j] = min(f[d[i] + 1][j] , f[i][j] + w[i]);
            f[i + 1][j + 1] = min(f[i + 1][j + 1] , f[i][j]);
        }
    }
    cout<<f[cl][m]<<endl;
    return 0;
}
