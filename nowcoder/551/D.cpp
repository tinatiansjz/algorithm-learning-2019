#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
bool vis[500];
int kcount[500];
char s[maxn];
stack<char> st;
int main(){
    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    memset(vis, 0, sizeof(vis));
    memset(kcount, 0, sizeof(kcount));
    for(int i=0; s[i]; i++){
        kcount[s[i]]++;
    }
    for(int i=0;s[i];i++){
        kcount[s[i]]--;
        if(vis[s[i]])continue;
        while(!st.empty() && st.top() >= s[i] && kcount[st.top()]){
            vis[st.top()]=0;
            st.pop();
        }
        st.push(s[i]);
        vis[s[i]] = 1;
    }
    int t = 0;
    while(!st.empty()){
        s[t++] = st.top();
        st.pop();
    }
    for(int i=t-1; i>=0; i--){
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}