#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 250;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll d[maxn][maxn];
ll F(ll x){ll mod = x%233; return (mod*mod*mod + mod*mod) % 233;}
ll G(ll x){ll mod = x%233; return (mod*mod*mod - mod*mod) % 233;}
void init(){
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < 233; i++) d[i][i] = 0;
    for(int i = 0; i < 233; i++){
        if(d[i][F(i)] > 1) d[i][F(i)] = 1;
        if(d[i][G(i)] > 1) d[i][G(i)] = 1;
    }
}
void Floyd(){
    for(int k = 0; k < 233; k++)
        for(int i = 0; i < 233; i++)
            for(int j = 0; j < 233; j++)
                if(d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}
int main(){
    // freopen("in.txt", "r", stdin);
    init();
    Floyd();
    int T; cin >> T;
    while(T--){
        ll A, B;
        scanf("%lld%lld", &A, &B);
        if(A == B) {cout << "0" << endl; continue;}
        if(B >= 233) {cout << "-1" << endl; continue;}
        // if(A == 0 && B != 0) {cout << "-1" << endl; continue;}
        if(A < 233){
            if(d[A][B] < INF) cout << d[A][B] << endl;
            else cout << "-1" << endl;
        }else{
            ll s1 = F(A);
            ll s2 = G(A);
            if(min(d[s1][B], d[s2][B]) + 1 < INF) cout << min(d[s1][B], d[s2][B]) + 1 << endl;
            else cout << "-1" << endl;
        }
    }
    return 0;
}