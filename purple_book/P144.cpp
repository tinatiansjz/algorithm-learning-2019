//Using next[i] to implement linked lists
//2018/12/20    18:11
//UVa 11988
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int last, cur, next[maxn];
char s[maxn];
int main(){
    freopen("P144_in.txt", "r", stdin);
    while(scanf("%s", s+1) == 1){//input characters saved in s[1], s[2] ...
        int n = strlen(s+1);
        last = cur = 0;
        next[0] = 0;
        for(int i = 1; i <= n; i++){
            char ch = s[i];
            if(ch == '[') cur = 0;//move the cursor to the beginning of the sentense
            else if(ch == ']') cur = last;//move the cursor to the end of the sentense (so far)
            else{//insert the considered character
                next[i] = next[cur];
                next[cur] = i;
                if(cur == last) last = i;//更新“最后一个字符“编号
                cur = i;//move the cursor
            }
        }
        for(int i = next[0]; i; i = next[i]){
            printf("%c", s[i]);
        }
        cout << endl;
    }
    return 0;
}