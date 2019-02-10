//HDU-1622 Trees on the level
#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
struct Node{
    bool have_value;//是否被赋值过
    int v;
    Node *left, *right;
    Node():have_value(false),left(NULL),right(NULL){}//构造函数
};
Node* root;//二叉树的根节点
bool failed;
vector<int> ans;
const int maxn = 10000;
char s[maxn];
Node* newnode(){return new Node();}
void addnode(int v, char* s){
    int n = strlen(s);
    Node* u = root;//从根节点往下走
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            if(u->left == NULL) u->left = newnode();
            u = u->left;
        }else if(s[i] == 'R'){
            if(u->right == NULL) u->right = newnode();
            u = u->right;
        }//忽略其他的情况，即最后多余的右括号
    }
    if(u->have_value) failed = true;//已经赋过值，表明输入有误
    u->v = v;
    u->have_value = true;
}
void remove_tree(Node* u){
    if(u == NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}
bool read_input(){
    failed = false;
    remove_tree(root);
    root = newnode();
    for(;;){
        if(scanf("%s", s) != 1) return false;//整个输入结束
        if(!strcmp(s, "()")) break;//读到结束标志，退出循环
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',') + 1);
    }
    return true;
}
//层次遍历树
bool bfs(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node* u = q.front(); q.pop();
        if(!u->have_value) return false;
        ans.push_back(u->v);
        if(u->left != NULL) q.push(u->left);
        if(u->right != NULL) q.push(u->right);
    }
    return true;
}
int main(){
    freopen("HDU-1622_in.txt", "r", stdin);
    while(read_input()){
        bool out = bfs(ans);
        if(failed) cout << "not complete" << endl;
        else if(out){
            cout << ans[0];
            for(int i = 1; i <  ans.size(); i++){
                cout << " " << ans[i];
            }
            cout << endl;
        }else{
            cout << "not complete" << endl;
        }
    }
    return 0;
}
