// Trie
// 如果在字典树上插入新字符串的时候经过先前的叶子节点标记，则说明以该节点为叶子节点的路径上的字符串是当前插入字符串的前缀；
// 如果在字典树上插入新字符串的长度小于当前所在的分支，则说明当前插入字符串是经过当前路径的所有分支所标示的字符串的前缀。
#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 10;
const int maxm = 15;
char a[maxn][maxm];
const int CHARSET = 2, BASE = '0', MAXNODE = 100;
struct Trie{
    int tot, root, child[MAXNODE][CHARSET];
    bool flag[MAXNODE];
    void init(){
        memset(child[1], 0, sizeof(child[1]));
        flag[1] = false;
        root = tot = 1;
    }
    bool insert(const char* str){
        int* cur = &root;
        for(const char* p = str; *p; p++){
            cur = &child[*cur][*p-BASE];
            if(*cur == 0){
                *cur = ++tot;
                memset(child[tot], 0, sizeof(child[tot]));
                flag[tot] = false;
            }
            if(flag[*cur]) return false;
        }
        flag[*cur] = true;
        if(child[*cur][0] || child[*cur][1]) return false;
        return true;
    }
};
Trie tri;
bool flag = true;
void init(){
    tri.init();
    flag = true;
    memset(a, 0, sizeof(a));
}
int main(){
    // freopen("in.txt", "r", stdin);
    int line = 0, kase = 1;
    init();
    while(~scanf("%s", a[line])){
        if(a[line][0] == '9') {
            if(flag)
                printf("Set %d is immediately decodable\n", kase);
            else
                printf("Set %d is not immediately decodable\n", kase);
            init();
            line = 0; kase++; continue;
        }
        if(flag && !tri.insert(a[line])) flag = false;
        line++;
    }
    return 0;
}