// https://blog.csdn.net/niushuai666/article/details/6981689
// POJ-1182
// 加权并查集
// 2019/1/10    17:02
// p[x].relation = 0: 节点x与其父节点rootx是同类
// p[x].relation = 1: 节点x被父亲节点rootx吃
// p[x].relation = 2: 节点x吃父亲节点rootx
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50010;
struct node{
    int pre;
    int relation;
};
node p[maxn];
int ans = 0;
int find(int x){
    if(x == p[x].pre) return x;
    int fa = p[x].pre; //父节点
    p[x].pre = find(fa);//路径压缩
    p[x].relation = (p[x].relation + p[fa].relation)%3;//关系域更新
    return p[x].pre;
}
void init(){
    for(int i = 1; i <= maxn; i++){
        p[i].pre = i;
        p[i].relation = 0;
    }
    ans = 0;
}
void debug(int line, int i){
    cout << "Line" << line << ": " << i << " " << ans << endl;
}
int main(){
    freopen("1182_in.txt", "r", stdin);
    init();
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++){
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if(a>n || b>n){
            ans++;
            debug(43, i);
            continue;
        }
        if(op == 2 && a == b){
            ans++;
            debug(47, i);
            continue;
        }
        int root1 = find(a);
        int root2 = find(b);
        if(root1 != root2){// 两棵树合并
            p[root1].pre = root2;
            if(op == 1)//同类
                p[root1].relation = ((3-p[a].relation)+p[b].relation)%3;
            else//a吃b
                p[root1].relation = ((3-p[a].relation)+2+p[b].relation)%3;
        }else{
            if(op == 1 && p[a].relation != p[b].relation){
                ans++;
                debug(60, i);
                continue;
            }
            if(op == 2 && ((p[a].relation + (3-p[b].relation))%3 != 2)){
                ans++;
                debug(65, i);
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
