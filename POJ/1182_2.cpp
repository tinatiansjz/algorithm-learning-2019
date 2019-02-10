// https://blog.csdn.net/waduan2/article/details/77459865
// 2019/1/11 10:33
// 加权并查集
// v[x] = 0: 节点x与其父节点rootx是同类
// v[x] = 1: 节点x被父亲节点rootx吃
// v[x] = 2: 节点x吃父亲节点rootx
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50000+10;
int ans;
int fa[maxn];// 保存父节点（根节点）
int v[maxn];// 记录此节点与父节点间的关系
int find(int x){
    if(fa[x] == x) return x;
    int tmp = fa[x];
    // int tmp;
    fa[x] = find(fa[x]);// 路径压缩
    v[x] = (v[x]+v[tmp])%3; //更改与根节点的关系 （向量思想）
    return fa[x];
}
void init(){
    for(int i = 0; i < maxn; i++){
        fa[i] = i; v[i]= 0;
    }
    ans = 0;
}
void debug(int line, int i){
    printf("Line%d: %d, ans = %d\n", line, i+1, ans);
}
int main(){
    // freopen("1182_in.txt", "r", stdin);
    int n, m;
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if((k == 2 && x == y) || x > n || y > n){
            ans++; 
            // debug(41, i);
            continue;
        }
        int rootx = find(x), rooty = find(y);// 一定要先用rootx和rooty存储
        if(k == 1){
            if(rootx == rooty){
                if(v[x] != v[y]){
                    ans++;
                    // debug(48, i);
                }
            }else{
                v[rootx] = (v[y]+3-v[x])%3;
                fa[rootx] = rooty;
            }
        }
        if(k == 2){
            if(rootx == rooty){

                if((v[x]+3-v[y])%3 != 2){
                    // printf("v[x]=%d, v[y]=%d\n", v[x], v[y]);
                    ans++;
                    // debug(58, i);
                }
            }else{
                // if(i == 1) printf("true\n");
                fa[rootx] = rooty;
                v[rootx] = (3-v[x]+2+v[y])%3;
            }
        }
        // printf("%d\n", i+1);
        // for(int j = 1; j <= 5; j++)
        //     printf("fa[%d] = %d ", j, fa[j]);
        // printf("\n");
        // for(int j = 1; j <= 5; j++)
        //     printf("v[%d] =  %d ", j, v[j]);
        // printf("\n");
    }
    printf("%d\n", ans);
    return 0;
}
