// HDU-1754 线段树(区间最值)
// 线段树 区间最值 单点更新
// 2019/2/25 21:03
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;
const int maxn = 2e5+5;
const int maxnode = maxn << 2;
int a[maxn];
int n, m;
int op, qL, qR, p, v; //qL和qR为全局变量，询问区间[qL, qR]
struct IntervalTree{
    int maxv[maxnode];
    void build(int o, int L, int R){
        if(L == R) {maxv[o] = a[L]; return;}
        int M = L + (R-L)/2;
        build(o<<1, L, M);
        build(o<<1|1, M+1, R);
        maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
    }
    void update(int o, int L, int R){ // root, left, right
        int M = L + (R-L)/2;
        if(L == R) maxv[o] = v; // 叶节点,直接更新maxv
        else{
            //先递归更新左子树或右子树
            if(p <= M) update(o<<1, L, M);
            else update(o<<1|1, M+1, R);
            //然后再计算本节点的maxv
            maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
        }
    }
    int query(int o, int L, int R){
        int M = L + (R-L)/2, ans = -INF;
        if(qL <= L && R <= qR) return maxv[o];//当节点完全包含在查询区间内
        if(qL <= M) ans = max(ans, query(o<<1, L, M));//往左走
        if(M < qR) ans = max(ans, query(o<<1|1, M+1, R));//往右走
        return ans;
    }
    void debug(){
        for(int i = 1; i < n<<2; i++)
            cout << maxv[i] << " ";
        cout << endl;
    }
};
IntervalTree tree;
int main(){
    // freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2){
        memset(&tree, 0, sizeof(tree));
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        tree.build(1, 1, n);
        // tree.debug();
        while(m--){
            do{op = getchar();} while(op == '\n' || op == ' ');
            if(op == 'U'){
                scanf("%d%d", &p, &v);
                tree.update(1, 1, n); // 修改树节点，或者是建树的过程
            }else{
                scanf("%d%d", &qL, &qR);
                printf("%d\n", tree.query(1, 1, n));
            }
        }
    }
    return 0;
}
