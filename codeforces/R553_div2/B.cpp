// http://codeforces.com/contest/1151/problem/B
// 2019/4/19
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 500+5;
int a[maxn][maxn];
int unique[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int n, m; scanf("%d%d", &n, &m);
    bool check = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] != a[i][0]){check = true; unique[i] = j;}
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans ^= a[i][0];
    if(!check && !ans){
        printf("NIE\n");
    }else{
        printf("TAK\n");
        if(ans){
            for(int i = 0; i < n; i++) printf("1 ");
            printf("\n");
        }else{
            for(int i = 0; i < n; i++){
                if(check && unique[i]){printf("%d ", unique[i]+1); check = false;}
                else printf("1 ");
            }
            printf("\n");
        }
    }
    return 0;
}